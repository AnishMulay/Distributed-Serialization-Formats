#pragma once

#include "common/serializer_interface.h"
#include <pugixml.hpp>

namespace benchmark {

class XmlSerializer : public SerializerInterface {
public:
    std::string format_name() const override {
        return "XML";
    }
    
    std::vector<uint8_t> serialize_metadata(const FileMetadata& metadata) override;
    FileMetadata deserialize_metadata(const std::vector<uint8_t>& data) override;
    
    std::vector<uint8_t> serialize_block(const FileBlock& block) override;
    FileBlock deserialize_block(const std::vector<uint8_t>& data) override;
    
private:
    // Helper methods for conversion between FileMetadata and XML
    void metadata_to_xml(const FileMetadata& metadata, pugi::xml_node& root);
    FileMetadata xml_to_metadata(const pugi::xml_document& doc);
    
    // Helper methods for conversion between FileBlock and XML
    void block_to_xml(const FileBlock& block, pugi::xml_node& root);
    FileBlock xml_to_block(const pugi::xml_document& doc);
    
    // Helper methods for base64 encoding/decoding
    std::string base64_encode(const std::vector<uint8_t>& data);
    std::vector<uint8_t> base64_decode(const std::string& encoded);
};

} // namespace benchmark