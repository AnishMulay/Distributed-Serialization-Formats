#include <iostream>
#include <cassert>
#include <set>
#include "common/test_data_generator.h"

using namespace benchmark;

void test_metadata_generation() {
    TestDataGenerator generator(42); // Fixed seed for reproducibility
    
    // Generate a metadata object
    FileMetadata metadata = generator.generate_metadata();
    
    // Basic validation
    assert(!metadata.name.empty());
    assert(!metadata.path.empty());
    assert(metadata.size > 0);
    assert(metadata.created_at > 0);
    assert(metadata.last_modified > 0);
    assert(!metadata.tags.empty());
    assert(metadata.permissions >= 0600 && metadata.permissions <= 0777);
    assert(!metadata.owner.empty());
    assert(!metadata.group.empty());
    
    std::cout << "Metadata generation test passed!" << std::endl;
}

void test_block_generation() {
    TestDataGenerator generator(42); // Fixed seed for reproducibility
    
    // Generate blocks of different sizes
    std::vector<size_t> sizes = {1024, 4096, 16384};
    
    for (size_t size : sizes) {
        FileBlock block = generator.generate_block(size);
        
        // Basic validation
        assert(!block.block_id.empty());
        assert(block.data.size() == size);
        assert(block.checksum > 0);
        
        // Generate another block with the same size
        FileBlock another_block = generator.generate_block(size);
        
        // Ensure blocks are different
        assert(block.block_id != another_block.block_id);
        assert(block.data != another_block.data);
        assert(block.checksum != another_block.checksum);
    }
    
    std::cout << "Block generation test passed!" << std::endl;
}

void test_batch_generation() {
    TestDataGenerator generator(42); // Fixed seed for reproducibility
    
    // Generate a batch of metadata
    size_t batch_size = 10;
    std::vector<FileMetadata> metadata_batch = generator.generate_metadata_batch(batch_size);
    
    // Basic validation
    assert(metadata_batch.size() == batch_size);
    
    // Check that all metadata objects are unique
    std::set<std::string> names;
    for (const auto& metadata : metadata_batch) {
        names.insert(metadata.name);
    }
    assert(names.size() == batch_size);
    
    // Generate a batch of blocks
    std::vector<size_t> sizes = {1024, 2048, 4096, 8192, 16384};
    std::vector<FileBlock> block_batch = generator.generate_block_batch(sizes);
    
    // Basic validation
    assert(block_batch.size() == sizes.size());
    
    // Check that offsets are correctly set
    uint64_t expected_offset = 0;
    for (size_t i = 0; i < block_batch.size(); ++i) {
        assert(block_batch[i].offset == expected_offset);
        assert(block_batch[i].data.size() == sizes[i]);
        expected_offset += sizes[i];
    }
    
    std::cout << "Batch generation test passed!" << std::endl;
}

int main() {
    std::cout << "Running test data generator tests..." << std::endl;
    
    test_metadata_generation();
    test_block_generation();
    test_batch_generation();
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}