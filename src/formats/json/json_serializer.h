#pragma once

#include "common/serializer_interface.h"
#include <nlohmann/json.hpp>

namespace benchmark {

class JsonSerializer : public SerializerInterface {
public:
    std::string format_name() const override {
        return "JSON";
    }
    
    std::vector<uint8_t> serialize_metadata(const FileMetadata& metadata) override;
    FileMetadata deserialize_metadata(const std::vector<uint8_t>& data) override;
    
    std::vector<uint8_t> serialize_block(const FileBlock& block) override;
    FileBlock deserialize_block(const std::vector<uint8_t>& data) override;
    
private:
    // Helper methods for conversion between FileMetadata and JSON
    nlohmann::json metadata_to_json(const FileMetadata& metadata);
    FileMetadata json_to_metadata(const nlohmann::json& j);
    
    // Helper methods for conversion between FileBlock and JSON
    nlohmann::json block_to_json(const FileBlock& block);
    FileBlock json_to_block(const nlohmann::json& j);
};

} // namespace benchmark