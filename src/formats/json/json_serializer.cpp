#include "formats/json/json_serializer.h"
#include <algorithm>
#include <stdexcept>
#include "common/utilities.h"

namespace benchmark {

// RFC 4648 compliant Base64 implementation
namespace {
    const std::string base64_chars = 
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

    std::string base64_encode(const std::vector<uint8_t>& data) {
        std::string encoded;
        int i = 0, j = 0;
        unsigned char char_array_3[3], char_array_4[4];

        for (const auto& byte : data) {
            char_array_3[i++] = byte;
            if (i == 3) {
                char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + 
                                 ((char_array_3[1] & 0xf0) >> 4);
                char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + 
                                 ((char_array_3[2] & 0xc0) >> 6);
                char_array_4[3] = char_array_3[2] & 0x3f;

                for (i = 0; i < 4; i++)
                    encoded += base64_chars[char_array_4[i]];
                i = 0;
            }
        }

        if (i) {
            for (j = i; j < 3; j++)
                char_array_3[j] = 0;

            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + 
                             ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + 
                             ((char_array_3[2] & 0xc0) >> 6);

            for (j = 0; j < i + 1; j++)
                encoded += base64_chars[char_array_4[j]];

            while (i++ < 3)
                encoded += '=';
        }

        return encoded;
    }

    std::vector<uint8_t> base64_decode(const std::string& encoded) {
        size_t in_len = encoded.size();
        int i = 0, j = 0, in_ = 0;
        unsigned char char_array_4[4], char_array_3[3];
        std::vector<uint8_t> decoded;

        while (in_len-- && encoded[in_] != '=') {
            char_array_4[i++] = encoded[in_]; in_++;
            if (i == 4) {
                for (i = 0; i < 4; i++)
                    char_array_4[i] = static_cast<unsigned char>(
                        base64_chars.find(char_array_4[i]));

                char_array_3[0] = (char_array_4[0] << 2) + 
                                  ((char_array_4[1] & 0x30) >> 4);
                char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + 
                                  ((char_array_4[2] & 0x3c) >> 2);
                char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + 
                                   char_array_4[3];

                for (i = 0; i < 3; i++)
                    decoded.push_back(char_array_3[i]);
                i = 0;
            }
        }

        if (i) {
            for (j = 0; j < i; j++)
                char_array_4[j] = static_cast<unsigned char>(
                    base64_chars.find(char_array_4[j]));

            char_array_3[0] = (char_array_4[0] << 2) + 
                              ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + 
                              ((char_array_4[2] & 0x3c) >> 2);

            for (j = 0; j < i - 1; j++)
                decoded.push_back(char_array_3[j]);
        }

        return decoded;
    }
}

std::vector<uint8_t> JsonSerializer::serialize_metadata(const FileMetadata& metadata) {
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
    
    std::string json_str = j.dump();
    return std::vector<uint8_t>(json_str.begin(), json_str.end());
}

FileMetadata JsonSerializer::deserialize_metadata(const std::vector<uint8_t>& data) {
    std::string json_str(data.begin(), data.end());
    auto j = nlohmann::json::parse(json_str);
    
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

std::vector<uint8_t> JsonSerializer::serialize_block(const FileBlock& block) {
    nlohmann::json j;
    j["block_id"] = block.block_id;
    j["offset"] = block.offset;
    j["data"] = base64_encode(block.data);
    j["checksum"] = block.checksum;
    
    std::string json_str = j.dump();
    return std::vector<uint8_t>(json_str.begin(), json_str.end());
}

FileBlock JsonSerializer::deserialize_block(const std::vector<uint8_t>& data) {
    std::string json_str(data.begin(), data.end());
    auto j = nlohmann::json::parse(json_str);
    
    FileBlock block;
    block.block_id = j["block_id"].get<std::string>();
    block.offset = j["offset"].get<uint64_t>();
    block.data = base64_decode(j["data"].get<std::string>());
    block.checksum = j["checksum"].get<uint32_t>();
    
    // Verify checksum
    uint32_t calculated = calculate_checksum(block.data);
    if (calculated != block.checksum) {
        throw std::runtime_error("Checksum mismatch after deserialization");
    }
    
    return block;
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