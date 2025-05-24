#include "formats/protobuf/protobuf_serializer.h"
#include <google/protobuf/stubs/common.h>

namespace benchmark {

ProtobufSerializer::ProtobufSerializer() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;
}

ProtobufSerializer::~ProtobufSerializer() {
    google::protobuf::ShutdownProtobufLibrary();
}

std::vector<uint8_t> ProtobufSerializer::serialize_metadata(const FileMetadata& metadata) {
    // Convert metadata to Protocol Buffers
    proto::FileMetadataProto proto = metadata_to_proto(metadata);
    
    // Serialize the Protocol Buffers message
    std::string serialized;
    proto.SerializeToString(&serialized);
    
    // Convert string to vector<uint8_t>
    return std::vector<uint8_t>(serialized.begin(), serialized.end());
}

FileMetadata ProtobufSerializer::deserialize_metadata(const std::vector<uint8_t>& data) {
    // Convert vector<uint8_t> to string
    std::string serialized(data.begin(), data.end());
    
    // Parse the Protocol Buffers message
    proto::FileMetadataProto proto;
    proto.ParseFromString(serialized);
    
    // Convert Protocol Buffers to metadata
    return proto_to_metadata(proto);
}

std::vector<uint8_t> ProtobufSerializer::serialize_block(const FileBlock& block) {
    // Convert block to Protocol Buffers
    proto::FileBlockProto proto = block_to_proto(block);
    
    // Serialize the Protocol Buffers message
    std::string serialized;
    proto.SerializeToString(&serialized);
    
    // Convert string to vector<uint8_t>
    return std::vector<uint8_t>(serialized.begin(), serialized.end());
}

FileBlock ProtobufSerializer::deserialize_block(const std::vector<uint8_t>& data) {
    // Convert vector<uint8_t> to string
    std::string serialized(data.begin(), data.end());
    
    // Parse the Protocol Buffers message
    proto::FileBlockProto proto;
    proto.ParseFromString(serialized);
    
    // Convert Protocol Buffers to block
    return proto_to_block(proto);
}

proto::FileMetadataProto ProtobufSerializer::metadata_to_proto(const FileMetadata& metadata) {
    proto::FileMetadataProto proto;
    
    proto.set_name(metadata.name);
    proto.set_path(metadata.path);
    proto.set_size(metadata.size);
    proto.set_created_at(metadata.created_at);
    proto.set_last_modified(metadata.last_modified);
    
    // Add tags
    for (const auto& tag : metadata.tags) {
        proto.add_tags(tag);
    }
    
    proto.set_permissions(metadata.permissions);
    proto.set_owner(metadata.owner);
    proto.set_group(metadata.group);
    
    return proto;
}

FileMetadata ProtobufSerializer::proto_to_metadata(const proto::FileMetadataProto& proto) {
    FileMetadata metadata;
    
    metadata.name = proto.name();
    metadata.path = proto.path();
    metadata.size = proto.size();
    metadata.created_at = proto.created_at();
    metadata.last_modified = proto.last_modified();
    
    // Add tags
    metadata.tags.reserve(proto.tags_size());
    for (int i = 0; i < proto.tags_size(); ++i) {
        metadata.tags.push_back(proto.tags(i));
    }
    
    metadata.permissions = proto.permissions();
    metadata.owner = proto.owner();
    metadata.group = proto.group();
    
    return metadata;
}

proto::FileBlockProto ProtobufSerializer::block_to_proto(const FileBlock& block) {
    proto::FileBlockProto proto;
    
    proto.set_block_id(block.block_id);
    proto.set_offset(block.offset);
    proto.set_data(std::string(block.data.begin(), block.data.end()));
    proto.set_checksum(block.checksum);
    
    return proto;
}

FileBlock ProtobufSerializer::proto_to_block(const proto::FileBlockProto& proto) {
    FileBlock block;
    
    block.block_id = proto.block_id();
    block.offset = proto.offset();
    
    const std::string& data = proto.data();
    block.data.assign(data.begin(), data.end());
    
    block.checksum = proto.checksum();
    
    return block;
}

} // namespace benchmark