#include "formats/xml/xml_serializer.h"
#include <sstream>
#include <stdexcept>

static const std::string base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

inline bool is_base64(unsigned char c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}

namespace benchmark {

std::vector<uint8_t> XmlSerializer::serialize_metadata(const FileMetadata& metadata) {
    pugi::xml_document doc;
    
    // Create root element
    pugi::xml_node root = doc.append_child("FileMetadata");
    
    // Add metadata to XML
    metadata_to_xml(metadata, root);
    
    // Save XML to string
    std::ostringstream oss;
    doc.save(oss);
    std::string xml_str = oss.str();
    
    // Convert string to vector<uint8_t>
    return std::vector<uint8_t>(xml_str.begin(), xml_str.end());
}

FileMetadata XmlSerializer::deserialize_metadata(const std::vector<uint8_t>& data) {
    // Convert vector<uint8_t> to string
    std::string xml_str(data.begin(), data.end());
    
    // Parse XML
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(xml_str.c_str());
    
    if (!result) {
        throw std::runtime_error("XML parse error: " + std::string(result.description()));
    }
    
    // Convert XML to metadata
    return xml_to_metadata(doc);
}

std::vector<uint8_t> XmlSerializer::serialize_block(const FileBlock& block) {
    pugi::xml_document doc;
    
    // Create root element
    pugi::xml_node root = doc.append_child("FileBlock");
    
    // Add block to XML
    block_to_xml(block, root);
    
    // Save XML to string
    std::ostringstream oss;
    doc.save(oss);
    std::string xml_str = oss.str();
    
    // Convert string to vector<uint8_t>
    return std::vector<uint8_t>(xml_str.begin(), xml_str.end());
}

FileBlock XmlSerializer::deserialize_block(const std::vector<uint8_t>& data) {
    // Convert vector<uint8_t> to string
    std::string xml_str(data.begin(), data.end());
    
    // Parse XML
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(xml_str.c_str());
    
    if (!result) {
        throw std::runtime_error("XML parse error: " + std::string(result.description()));
    }
    
    // Convert XML to block
    return xml_to_block(doc);
}

void XmlSerializer::metadata_to_xml(const FileMetadata& metadata, pugi::xml_node& root) {
    root.append_child("name").text().set(metadata.name.c_str());
    root.append_child("path").text().set(metadata.path.c_str());
    root.append_child("size").text().set(metadata.size);
    root.append_child("created_at").text().set(metadata.created_at);
    root.append_child("last_modified").text().set(metadata.last_modified);
    
    // Add tags
    pugi::xml_node tags_node = root.append_child("tags");
    for (const auto& tag : metadata.tags) {
        tags_node.append_child("tag").text().set(tag.c_str());
    }
    
    root.append_child("permissions").text().set(metadata.permissions);
    root.append_child("owner").text().set(metadata.owner.c_str());
    root.append_child("group").text().set(metadata.group.c_str());
}

FileMetadata XmlSerializer::xml_to_metadata(const pugi::xml_document& doc) {
    FileMetadata metadata;
    
    pugi::xml_node root = doc.child("FileMetadata");
    
    metadata.name = root.child("name").text().get();
    metadata.path = root.child("path").text().get();
    metadata.size = root.child("size").text().as_ullong();
    metadata.created_at = root.child("created_at").text().as_ullong();
    metadata.last_modified = root.child("last_modified").text().as_ullong();
    
    // Get tags
    pugi::xml_node tags_node = root.child("tags");
    for (pugi::xml_node tag_node = tags_node.child("tag"); tag_node; tag_node = tag_node.next_sibling("tag")) {
        metadata.tags.push_back(tag_node.text().get());
    }
    
    metadata.permissions = root.child("permissions").text().as_uint();
    metadata.owner = root.child("owner").text().get();
    metadata.group = root.child("group").text().get();
    
    return metadata;
}

void XmlSerializer::block_to_xml(const FileBlock& block, pugi::xml_node& root) {
    root.append_child("block_id").text().set(block.block_id.c_str());
    root.append_child("offset").text().set(block.offset);
    root.append_child("data").text().set(base64_encode(block.data).c_str());
    root.append_child("checksum").text().set(block.checksum);
}

FileBlock XmlSerializer::xml_to_block(const pugi::xml_document& doc) {
    FileBlock block;
    
    pugi::xml_node root = doc.child("FileBlock");
    
    block.block_id = root.child("block_id").text().get();
    block.offset = root.child("offset").text().as_ullong();
    block.data = base64_decode(root.child("data").text().get());
    block.checksum = root.child("checksum").text().as_uint();
    
    return block;
}

std::string XmlSerializer::base64_encode(const std::vector<uint8_t>& data) {
    static const char base64_chars[] = 
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    
    std::string result;
    result.reserve(((data.size() + 2) / 3) * 4);
    
    for (size_t i = 0; i < data.size(); i += 3) {
        uint32_t octet_a = i < data.size() ? data[i] : 0;
        uint32_t octet_b = i + 1 < data.size() ? data[i + 1] : 0;
        uint32_t octet_c = i + 2 < data.size() ? data[i + 2] : 0;
        
        uint32_t triple = (octet_a << 16) + (octet_b << 8) + octet_c;
        
        result.push_back(base64_chars[(triple >> 18) & 0x3F]);
        result.push_back(base64_chars[(triple >> 12) & 0x3F]);
        result.push_back(base64_chars[(triple >> 6) & 0x3F]);
        result.push_back(base64_chars[triple & 0x3F]);
    }
    
    // Add padding
    int mod_table[] = {0, 2, 1};
    int padding = mod_table[data.size() % 3];
    
    for (int i = 0; i < padding; ++i) {
        result[result.size() - 1 - i] = '=';
    }
    
    return result;
}

std::vector<uint8_t> XmlSerializer::base64_decode(std::string const& encoded_string) {
    int in_len = encoded_string.size();
    int i = 0;
    int in_ = 0;
    uint8_t char_array_4[4], char_array_3[3];
    std::vector<uint8_t> ret;

    while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
        char_array_4[i++] = encoded_string[in_]; in_++;
        if (i ==4) {
            for (i = 0; i <4; i++)
                char_array_4[i] = base64_chars.find(char_array_4[i]);

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (i = 0; (i < 3); i++)
                ret.push_back(char_array_3[i]);
            i = 0;
        }
    }

    if (i) {
        for (int j = i; j <4; j++)
            char_array_4[j] = 0;

        for (int j = 0; j <4; j++)
            char_array_4[j] = base64_chars.find(char_array_4[j]);

        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

        for (int j = 0; (j < i - 1); j++) ret.push_back(char_array_3[j]);
    }

    return ret;
}

} // namespace benchmark