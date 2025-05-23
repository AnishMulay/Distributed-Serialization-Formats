#pragma once

#include <string>
#include <vector>
#include <ctime>
#include <cstdint>
#include "utilities.h"

namespace benchmark {

/**
 * Represents metadata for a file in a distributed file system
 */
struct FileMetadata {
    std::string name;              // File name
    std::string path;              // Full path
    uint64_t size;                 // Size in bytes
    time_t created_at;             // Creation time
    time_t last_modified;          // Last modification time
    std::vector<std::string> tags; // Optional tags/attributes
    uint32_t permissions;          // Unix-style permissions
    std::string owner;             // Owner name/ID
    std::string group;             // Group name/ID
    
    // Constructor with default values
    FileMetadata() 
        : name("")
        , path("")
        , size(0)
        , created_at(0)
        , last_modified(0)
        , permissions(0644)
        , owner("root")
        , group("root")
    {}
    
    // Check if two metadata objects are equal (for testing)
    bool operator==(const FileMetadata& other) const {
        return name == other.name &&
               path == other.path &&
               size == other.size &&
               created_at == other.created_at &&
               last_modified == other.last_modified &&
               tags == other.tags &&
               permissions == other.permissions &&
               owner == other.owner &&
               group == other.group;
    }
    
    // Check if two metadata objects are not equal
    bool operator!=(const FileMetadata& other) const {
        return !(*this == other);
    }
};

/**
 * Represents a block of file data
 */
struct FileBlock {
    std::string block_id;           // Unique block identifier
    uint64_t offset;                // Offset in original file
    std::vector<uint8_t> data;      // Actual block data
    uint32_t checksum;              // Checksum for data integrity
    
    // Constructor with default values
    FileBlock()
        : block_id("")
        , offset(0)
        , checksum(0)
    {}
    
    bool validate_checksum() const {
        return benchmark::calculate_checksum(data) == checksum;
    }

    // Check if two blocks are equal (for testing)
    bool operator==(const FileBlock& other) const {
        return block_id == other.block_id &&
               offset == other.offset &&
               data == other.data &&
               checksum == other.checksum;
    }
    
    // Check if two blocks are not equal
    bool operator!=(const FileBlock& other) const {
        return !(*this == other);
    }
};

} // namespace benchmark