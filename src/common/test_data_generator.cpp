#include "common/test_data_generator.h"
#include <algorithm>
#include <sstream>
#include <iomanip>

namespace benchmark {

TestDataGenerator::TestDataGenerator(unsigned int seed)
    : rng_(seed), byte_dist_(0, 255) {
}

FileMetadata TestDataGenerator::generate_metadata(size_t tag_count) {
    FileMetadata metadata;
    
    // Generate a random file name
    std::string name = random_string(8) + ".dat";
    metadata.name = name;
    
    // Generate a random path
    metadata.path = "/data/" + random_string(5) + "/" + name;
    
    // Generate a random file size (100 bytes to 10MB)
    std::uniform_int_distribution<uint64_t> size_dist(100, 10 * 1024 * 1024);
    metadata.size = size_dist(rng_);
    
    // Set timestamps (within the last year)
    std::uniform_int_distribution<time_t> time_dist(
        std::time(nullptr) - 365 * 24 * 60 * 60,
        std::time(nullptr)
    );
    metadata.created_at = time_dist(rng_);
    metadata.last_modified = time_dist(rng_);
    
    // Generate random tags
    metadata.tags.clear();
    std::vector<std::string> possible_tags = {
        "document", "image", "video", "audio", "archive",
        "temp", "system", "user", "application", "cache",
        "backup", "project", "data", "config", "log"
    };
    
    std::uniform_int_distribution<size_t> tag_idx_dist(0, possible_tags.size() - 1);
    for (size_t i = 0; i < tag_count; ++i) {
        metadata.tags.push_back(possible_tags[tag_idx_dist(rng_)]);
    }
    
    // Generate random permissions (between 0600 and 0777)
    std::uniform_int_distribution<uint32_t> perm_dist(0600, 0777);
    metadata.permissions = perm_dist(rng_);
    
    // Set owner and group
    std::vector<std::string> possible_users = {
        "root", "admin", "user", "guest", "daemon",
        "system", "john", "alice", "bob", "carol"
    };
    
    std::uniform_int_distribution<size_t> user_idx_dist(0, possible_users.size() - 1);
    metadata.owner = possible_users[user_idx_dist(rng_)];
    metadata.group = possible_users[user_idx_dist(rng_)];
    
    return metadata;
}

FileBlock TestDataGenerator::generate_block(size_t size_bytes, uint64_t offset) {
    FileBlock block;
    
    // Generate a unique block ID (hex string)
    std::stringstream ss;
    std::uniform_int_distribution<uint32_t> id_dist(0, 0xFFFFFFFF);
    ss << std::hex << std::setw(8) << std::setfill('0') << id_dist(rng_);
    block.block_id = ss.str();
    
    // Set the offset
    block.offset = offset;
    
    // Generate random data
    block.data.resize(size_bytes);
    std::generate(block.data.begin(), block.data.end(), 
                  [this]() { return byte_dist_(rng_); });
    
    // Calculate checksum
    block.checksum = calculate_checksum(block.data);
    
    return block;
}

std::vector<FileMetadata> TestDataGenerator::generate_metadata_batch(size_t count) {
    std::vector<FileMetadata> batch;
    batch.reserve(count);
    
    for (size_t i = 0; i < count; ++i) {
        batch.push_back(generate_metadata());
    }
    
    return batch;
}

std::vector<FileBlock> TestDataGenerator::generate_block_batch(const std::vector<size_t>& sizes) {
    std::vector<FileBlock> batch;
    batch.reserve(sizes.size());
    
    uint64_t current_offset = 0;
    for (size_t size : sizes) {
        batch.push_back(generate_block(size, current_offset));
        current_offset += size;
    }
    
    return batch;
}

std::string TestDataGenerator::random_string(size_t length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    std::uniform_int_distribution<size_t> dist(0, sizeof(charset) - 2);
    
    std::string result(length, ' ');
    for (char& c : result) {
        c = charset[dist(rng_)];
    }
    
    return result;
}

uint32_t TestDataGenerator::calculate_checksum(const std::vector<uint8_t>& data) {
    // Simple Adler-32 checksum
    uint32_t a = 1, b = 0;
    
    for (const auto& byte : data) {
        a = (a + byte) % 65521;
        b = (b + a) % 65521;
    }
    
    return (b << 16) | a;
}

} // namespace benchmark