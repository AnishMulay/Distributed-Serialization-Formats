#pragma once

#include <vector>
#include <string>
#include "common/data_structures.h"

namespace benchmark {

/**
 * Common interface for all serializers
 */
class SerializerInterface {
public:
    virtual ~SerializerInterface() = default;
    
    // Format name (e.g., "JSON", "XML", etc.)
    virtual std::string format_name() const = 0;
    
    // Serialize metadata to binary string
    virtual std::vector<uint8_t> serialize_metadata(const FileMetadata& metadata) = 0;
    
    // Deserialize metadata from binary string
    virtual FileMetadata deserialize_metadata(const std::vector<uint8_t>& data) = 0;
    
    // Serialize file block to binary string
    virtual std::vector<uint8_t> serialize_block(const FileBlock& block) = 0;
    
    // Deserialize file block from binary string
    virtual FileBlock deserialize_block(const std::vector<uint8_t>& data) = 0;
};

} // namespace benchmark