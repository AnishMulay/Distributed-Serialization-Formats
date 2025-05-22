#pragma once

#include <vector>
#include <random>
#include "common/data_structures.h"

namespace benchmark {

class TestDataGenerator {
public:
    TestDataGenerator(unsigned int seed = std::random_device{}());
    
    // Generate file metadata with random values
    FileMetadata generate_metadata(size_t tag_count = 3);
    
    // Generate file block with random data of specified size
    FileBlock generate_block(size_t size_bytes, uint64_t offset = 0);
    
    // Generate a vector of file metadata entries
    std::vector<FileMetadata> generate_metadata_batch(size_t count);
    
    // Generate a vector of file blocks with specified sizes
    std::vector<FileBlock> generate_block_batch(const std::vector<size_t>& sizes);

private:
    std::mt19937 rng_;
    std::uniform_int_distribution<uint8_t> byte_dist_;
    
    // Helper method to generate a random string
    std::string random_string(size_t length);
    
    // Helper method to calculate simple checksum
    uint32_t calculate_checksum(const std::vector<uint8_t>& data);
};

} // namespace benchmark