#include <iostream>
#include <cassert>
#include <cmath>
#include "common/benchmark_runner.h"
#include "common/test_data_generator.h"

// Mock serializer for testing
class MockSerializer : public benchmark::SerializerInterface {
public:
    std::string format_name() const override {
        return "MockFormat";
    }
    
    std::vector<uint8_t> serialize_metadata(const benchmark::FileMetadata& metadata) override {
        // Simple mock implementation that just puts the name in a vector
        std::vector<uint8_t> result(metadata.name.begin(), metadata.name.end());
        return result;
    }
    
    benchmark::FileMetadata deserialize_metadata(const std::vector<uint8_t>& data) override {
        benchmark::FileMetadata result;
        result.name = std::string(data.begin(), data.end());
        return result;
    }
    
    std::vector<uint8_t> serialize_block(const benchmark::FileBlock& block) override {
        // For testing, just return the block data
        return block.data;
    }
    
    benchmark::FileBlock deserialize_block(const std::vector<uint8_t>& data) override {
        benchmark::FileBlock result;
        result.data = data;
        return result;
    }
};

int main() {
    std::cout << "Running benchmark runner tests..." << std::endl;
    
    // Create test data
    benchmark::TestDataGenerator generator;
    auto metadata = generator.generate_metadata();
    auto block = generator.generate_block(1024);
    
    // Create a mock serializer
    MockSerializer serializer;
    
    // Create a benchmark runner with a small number of iterations for testing
    benchmark::BenchmarkRunner runner(10);
    
    // Run benchmarks
    auto metadata_ser_result = runner.benchmark_metadata_serialization(serializer, metadata);
    auto serialized_metadata = serializer.serialize_metadata(metadata);
    auto metadata_deser_result = runner.benchmark_metadata_deserialization(serializer, serialized_metadata);
    
    auto block_ser_result = runner.benchmark_block_serialization(serializer, block);
    auto serialized_block = serializer.serialize_block(block);
    auto block_deser_result = runner.benchmark_block_deserialization(serializer, serialized_block);
    
    // Validate results
    assert(metadata_ser_result.format_name == "MockFormat");
    assert(metadata_ser_result.operation_name == "metadata_serialization");
    assert(metadata_ser_result.duration_ms >= 0.0);
    assert(metadata_ser_result.serialized_size_bytes == metadata.name.size());
    
    assert(metadata_deser_result.format_name == "MockFormat");
    assert(metadata_deser_result.operation_name == "metadata_deserialization");
    assert(metadata_deser_result.duration_ms >= 0.0);
    
    assert(block_ser_result.format_name == "MockFormat");
    assert(block_ser_result.operation_name == "block_serialization");
    assert(block_ser_result.duration_ms >= 0.0);
    assert(block_ser_result.serialized_size_bytes == block.data.size());
    
    assert(block_deser_result.format_name == "MockFormat");
    assert(block_deser_result.operation_name == "block_deserialization");
    assert(block_deser_result.duration_ms >= 0.0);
    
    // Print results
    std::vector<benchmark::BenchmarkResult> results = {
        metadata_ser_result,
        metadata_deser_result,
        block_ser_result,
        block_deser_result
    };
    
    benchmark::BenchmarkRunner::print_results(results);
    
    // Test CSV export
    benchmark::BenchmarkRunner::export_results_csv(results, "test_results.csv");
    
    std::cout << "All tests passed!" << std::endl;
    std::cout << "Results exported to test_results.csv" << std::endl;
    
    return 0;
}