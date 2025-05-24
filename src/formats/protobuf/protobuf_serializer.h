#pragma once

#include "common/serializer_interface.h"
#include "formats/protobuf/generated/schemas/protobuf/file_storage.pb.h"

namespace benchmark {

class ProtobufSerializer : public SerializerInterface {
public:
    ProtobufSerializer();
    ~ProtobufSerializer() override;
    
    std::string format_name() const override {
        return "Protocol Buffers";
    }
    
    std::vector<uint8_t> serialize_metadata(const FileMetadata& metadata) override;
    FileMetadata deserialize_metadata(const std::vector<uint8_t>& data) override;
    
    std::vector<uint8_t> serialize_block(const FileBlock& block) override;
    FileBlock deserialize_block(const std::vector<uint8_t>& data) override;
    
private:
    // Helper methods for conversion between FileMetadata and Protocol Buffers
    proto::FileMetadataProto metadata_to_proto(const FileMetadata& metadata);
    FileMetadata proto_to_metadata(const proto::FileMetadataProto& proto);
    
    // Helper methods for conversion between FileBlock and Protocol Buffers
    proto::FileBlockProto block_to_proto(const FileBlock& block);
    FileBlock proto_to_block(const proto::FileBlockProto& proto);
};

} // namespace benchmark