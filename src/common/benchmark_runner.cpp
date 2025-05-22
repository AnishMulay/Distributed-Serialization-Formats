#include "common/benchmark_runner.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <cassert>

namespace benchmark {

BenchmarkRunner::BenchmarkRunner(size_t iterations)
    : iterations_(iterations) {
}

BenchmarkResult BenchmarkRunner::benchmark_metadata_serialization(
    SerializerInterface& serializer,
    const FileMetadata& metadata) {
    
    // Estimate the data size (this is approximate)
    size_t data_size = metadata.name.size() + metadata.path.size() +
                       sizeof(metadata.size) + sizeof(metadata.created_at) +
                       sizeof(metadata.last_modified) +
                       std::accumulate(metadata.tags.begin(), metadata.tags.end(), 0,
                                     [](size_t sum, const std::string& tag) {
                                         return sum + tag.size();
                                     }) +
                       sizeof(metadata.permissions) +
                       metadata.owner.size() + metadata.group.size();
    
    // First serialize once to get the serialized size
    std::vector<uint8_t> serialized_data = serializer.serialize_metadata(metadata);
    
    // Run the benchmark
    return benchmark_operation(
        serializer.format_name(),
        "metadata_serialization",
        data_size,
        serialized_data.size(),
        [&]() { return serializer.serialize_metadata(metadata); }
    );
}

BenchmarkResult BenchmarkRunner::benchmark_metadata_deserialization(
    SerializerInterface& serializer,
    const std::vector<uint8_t>& serialized_data) {
    
    // Run the benchmark
    return benchmark_operation(
        serializer.format_name(),
        "metadata_deserialization",
        0,  // Input size is the serialized data
        serialized_data.size(),
        [&]() { return serializer.deserialize_metadata(serialized_data); }
    );
}

BenchmarkResult BenchmarkRunner::benchmark_block_serialization(
    SerializerInterface& serializer,
    const FileBlock& block) {
    
    // Estimate the data size
    size_t data_size = block.block_id.size() +
                       sizeof(block.offset) +
                       block.data.size() +
                       sizeof(block.checksum);
    
    // First serialize once to get the serialized size
    std::vector<uint8_t> serialized_data = serializer.serialize_block(block);
    
    // Run the benchmark
    return benchmark_operation(
        serializer.format_name(),
        "block_serialization",
        data_size,
        serialized_data.size(),
        [&]() { return serializer.serialize_block(block); }
    );
}

BenchmarkResult BenchmarkRunner::benchmark_block_deserialization(
    SerializerInterface& serializer,
    const std::vector<uint8_t>& serialized_data) {
    
    // Run the benchmark
    return benchmark_operation(
        serializer.format_name(),
        "block_deserialization",
        0,  // Input size is the serialized data
        serialized_data.size(),
        [&]() { return serializer.deserialize_block(serialized_data); }
    );
}

template<typename Func>
BenchmarkResult BenchmarkRunner::benchmark_operation(
    const std::string& format_name,
    const std::string& operation_name,
    size_t data_size_bytes,
    size_t serialized_size_bytes,
    Func&& operation) {
    
    // Run the operation once to warm up
    operation();
    
    // Measure the execution time
    std::vector<double> durations;
    durations.reserve(iterations_);
    
    for (size_t i = 0; i < iterations_; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        operation();
        auto end = std::chrono::high_resolution_clock::now();
        
        auto duration = std::chrono::duration<double, std::milli>(end - start).count();
        durations.push_back(duration);
    }
    
    // Calculate average duration (excluding outliers)
    std::sort(durations.begin(), durations.end());
    size_t outliers_to_remove = iterations_ / 10; // Remove 10% from each end
    
    double total_duration = 0.0;
    for (size_t i = outliers_to_remove; i < iterations_ - outliers_to_remove; ++i) {
        total_duration += durations[i];
    }
    
    double avg_duration = total_duration / (iterations_ - 2 * outliers_to_remove);
    
    // Create and return the benchmark result
    BenchmarkResult result;
    result.format_name = format_name;
    result.operation_name = operation_name;
    result.data_size_bytes = data_size_bytes;
    result.duration_ms = avg_duration;
    result.serialized_size_bytes = serialized_size_bytes;
    
    return result;
}

void BenchmarkRunner::print_results(const std::vector<BenchmarkResult>& results) {
    // Print header
    std::cout << std::left
              << std::setw(15) << "Format"
              << std::setw(25) << "Operation"
              << std::setw(15) << "Data Size (B)"
              << std::setw(15) << "Serialized (B)"
              << std::setw(15) << "Duration (ms)"
              << std::endl;
    
    std::cout << std::string(85, '-') << std::endl;
    
    // Print results
    for (const auto& result : results) {
        std::cout << std::left
                  << std::setw(15) << result.format_name
                  << std::setw(25) << result.operation_name
                  << std::setw(15) << result.data_size_bytes
                  << std::setw(15) << result.serialized_size_bytes
                  << std::setw(15) << std::fixed << std::setprecision(3) << result.duration_ms
                  << std::endl;
    }
}

void BenchmarkRunner::export_results_csv(
    const std::vector<BenchmarkResult>& results,
    const std::string& filename) {
    
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
        return;
    }
    
    // Write header
    file << "Format,Operation,DataSizeBytes,SerializedSizeBytes,DurationMs" << std::endl;
    
    // Write results
    for (const auto& result : results) {
        file << result.format_name << ","
             << result.operation_name << ","
             << result.data_size_bytes << ","
             << result.serialized_size_bytes << ","
             << std::fixed << std::setprecision(6) << result.duration_ms
             << std::endl;
    }
}

} // namespace benchmark