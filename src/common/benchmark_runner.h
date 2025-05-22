#pragma once

#include <vector>
#include <string>
#include <chrono>
#include <functional>
#include "common/data_structures.h"
#include "common/serializer_interface.h"

namespace benchmark {

struct BenchmarkResult {
    std::string format_name;
    std::string operation_name;
    size_t data_size_bytes;
    double duration_ms;
    size_t serialized_size_bytes;
};

class BenchmarkRunner {
public:
    // Constructor
    BenchmarkRunner(size_t iterations = 100);
    
    // Run serialization benchmark for metadata
    BenchmarkResult benchmark_metadata_serialization(
        SerializerInterface& serializer,
        const FileMetadata& metadata);
    
    // Run deserialization benchmark for metadata
    BenchmarkResult benchmark_metadata_deserialization(
        SerializerInterface& serializer,
        const std::vector<uint8_t>& serialized_data);
    
    // Run serialization benchmark for file block
    BenchmarkResult benchmark_block_serialization(
        SerializerInterface& serializer,
        const FileBlock& block);
    
    // Run deserialization benchmark for file block
    BenchmarkResult benchmark_block_deserialization(
        SerializerInterface& serializer,
        const std::vector<uint8_t>& serialized_data);
    
    // Print benchmark results
    static void print_results(const std::vector<BenchmarkResult>& results);
    
    // Export results to CSV
    static void export_results_csv(
        const std::vector<BenchmarkResult>& results,
        const std::string& filename);

private:
    size_t iterations_;
    
    // Generic benchmark function template
    template<typename Func>
    BenchmarkResult benchmark_operation(
        const std::string& format_name,
        const std::string& operation_name,
        size_t data_size_bytes,
        size_t serialized_size_bytes,
        Func&& operation);
};

} // namespace benchmark