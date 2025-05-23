#include "formats/json/json_serializer.h"
#include <string>

namespace benchmark {

std::vector<uint8_t> JsonSerializer::serialize_metadata(const FileMetadata& metadata) {
    // Convert metadata to JSON
    nlohmann::json j = metadata_to_json(metadata);
    
    // Convert JSON to string
    std::string json_str = j.dump();
    
    // Convert string to vector<uint8_t>
    return std::vector<uint8_t>(json_str.begin(), json_str.end());
}

FileMetadata JsonSerializer::deserialize_metadata(const std::vector<uint8_t>& data) {
    // Convert vector<uint8_t> to string
    std::string json_str(data.begin(), data.end());
    
    // Parse JSON
    nlohmann::json j = nlohmann::json::parse(json_str);
    
    // Convert JSON to metadata
    return json_to_metadata(j);
}

std::vector<uint8_t> JsonSerializer::serialize_block(const FileBlock& block) {
    // Convert block to JSON
    nlohmann::json j = block_to_json(block);
    
    // Convert JSON to string
    std::string json_str = j.dump();
    
    // Convert string to vector<uint8_t>
    return std::vector<uint8_t>(json_str.begin(), json_str.end());
}

FileBlock JsonSerializer::deserialize_block(const std::vector<uint8_t>& data) {
    // Convert vector<uint8_t> to string
    std::string json_str(data.begin(), data.end());
    
    // Parse JSON
    nlohmann::json j = nlohmann::json::parse(json_str);
    
    // Convert JSON to block
    return json_to_block(j);
}

nlohmann::json JsonSerializer::metadata_to_json(const FileMetadata& metadata) {
    nlohmann::json j;
    
    j["name"] = metadata.name;
    j["path"] = metadata.path;
    j["size"] = metadata.size;
    j["created_at"] = metadata.created_at;
    j["last_modified"] = metadata.last_modified;
    j["tags"] = metadata.tags;
    j["permissions"] = metadata.permissions;
    j["owner"] = metadata.owner;
    j["group"] = metadata.group;
    
    return j;
}

FileMetadata JsonSerializer::json_to_metadata(const nlohmann::json& j) {
    FileMetadata metadata;
    
    metadata.name = j["name"].get<std::string>();
    metadata.path = j["path"].get<std::string>();
    metadata.size = j["size"].get<uint64_t>();
    metadata.created_at = j["created_at"].get<time_t>();
    metadata.last_modified = j["last_modified"].get<time_t>();
    metadata.tags = j["tags"].get<std::vector<std::string>>();
    metadata.permissions = j["permissions"].get<uint32_t>();
    metadata.owner = j["owner"].get<std::string>();
    metadata.group = j["group"].get<std::string>();
    
    return metadata;
}

nlohmann::json JsonSerializer::block_to_json(const FileBlock& block) {
    nlohmann::json j;
    
    j["block_id"] = block.block_id;
    j["offset"] = block.offset;
    
    // Convert binary data to base64
    std::string base64_data;
    if (!block.data.empty()) {
        // This is a simple implementation; in a real-world scenario, 
        // you might want to use a proper base64 encoding library
        static const char base64_chars[] = 
            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
        
        base64_data.reserve(((block.data.size() + 2) / 3) * 4);
        
        for (size_t i = 0; i < block.data.size(); i += 3) {
            uint32_t octet_a = i < block.data.size() ? block.data[i] : 0;
            uint32_t octet_b = i + 1 < block.data.size() ? block.data[i + 1] : 0;
            uint32_t octet_c = i + 2 < block.data.size() ? block.data[i + 2] : 0;
            
            uint32_t triple = (octet_a << 16) + (octet_b << 8) + octet_c;
            
            base64_data.push_back(base64_chars[(triple >> 18) & 0x3F]);
            base64_data.push_back(base64_chars[(triple >> 12) & 0x3F]);
            base64_data.push_back(base64_chars[(triple >> 6) & 0x3F]);
            base64_data.push_back(base64_chars[triple & 0x3F]);
        }
        
        // Add padding
        int mod_table[] = {0, 2, 1};
        int padding = mod_table[block.data.size() % 3];
        
        for (int i = 0; i < padding; ++i) {
            base64_data[base64_data.size() - 1 - i] = '=';
        }
    }
    
    j["data"] = base64_data;
    j["checksum"] = block.checksum;
    
    return j;
}

FileBlock JsonSerializer::json_to_block(const nlohmann::json& j) {
    FileBlock block;
    
    block.block_id = j["block_id"].get<std::string>();
    block.offset = j["offset"].get<uint64_t>();
    
    // Convert base64 to binary data
    std::string base64_data = j["data"].get<std::string>();
    
    if (!base64_data.empty()) {
        // This is a simple implementation; in a real-world scenario, 
        // you might want to use a proper base64 decoding library
        static const unsigned char base64_table[256] = {
            64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
            64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
            64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 62, 64, 64, 64, 63,
            52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 64, 64, 64, 64, 64, 64,
            64,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
            15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 64, 64, 64, 64, 64,
            64, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
            41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 64, 64, 64, 64, 64,
            64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
            64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
            64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
            64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
            64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
            64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
            64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
            64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64
        };
        
        // Calculate the expected size of the decoded data
        size_t padding = 0;
        if (base64_data.size() >= 2) {
            if (base64_data[base64_data.size() - 1] == '=') ++padding;
            if (base64_data[base64_data.size() - 2] == '=') ++padding;
        }
        
        size_t decoded_size = ((base64_data.size() * 3) / 4) - padding;
        block.data.reserve(decoded_size);
        
        uint32_t temp = 0;
        size_t i = 0;
        
        while (i < base64_data.size()) {
            unsigned char c = base64_data[i++];
            if (c == '=' || base64_table[c] == 64) break;
            
            temp = (temp << 6) | base64_table[c];
            
            if (i % 4 == 0) {
                block.data.push_back((temp >> 16) & 0xFF);
                block.data.push_back((temp >> 8) & 0xFF);
                block.data.push_back(temp & 0xFF);
                temp = 0;
            }
        }
        
        if (i % 4 == 2) {
            temp = (temp << 12);
            block.data.push_back((temp >> 16) & 0xFF);
        } else if (i % 4 == 3) {
            temp = (temp << 6);
            block.data.push_back((temp >> 16) & 0xFF);
            block.data.push_back((temp >> 8) & 0xFF);
        }
    }
    
    block.checksum = j["checksum"].get<uint32_t>();
    
    return block;
}

} // namespace benchmark