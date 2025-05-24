#include "formats/msgpack/msgpack_serializer.h"

namespace benchmark {

std::vector<uint8_t> MessagePackSerializer::serialize_metadata(const FileMetadata& metadata) {
    // Serialize using MessagePack
    std::stringstream ss;
    msgpack::pack(ss, metadata);
    const std::string& str = ss.str();
    
    // Convert to vector<uint8_t>
    return std::vector<uint8_t>(str.begin(), str.end());
}

FileMetadata MessagePackSerializer::deserialize_metadata(const std::vector<uint8_t>& data) {
    // Create a MessagePack object
    msgpack::object_handle oh = msgpack::unpack(reinterpret_cast<const char*>(data.data()), data.size());
    msgpack::object obj = oh.get();
    
    // Convert to FileMetadata
    FileMetadata metadata;
    obj.convert(metadata);
    
    return metadata;
}

std::vector<uint8_t> MessagePackSerializer::serialize_block(const FileBlock& block) {
    // Serialize using MessagePack
    std::stringstream ss;
    msgpack::pack(ss, block);
    const std::string& str = ss.str();
    
    // Convert to vector<uint8_t>
    return std::vector<uint8_t>(str.begin(), str.end());
}

FileBlock MessagePackSerializer::deserialize_block(const std::vector<uint8_t>& data) {
    // Create a MessagePack object
    msgpack::object_handle oh = msgpack::unpack(reinterpret_cast<const char*>(data.data()), data.size());
    msgpack::object obj = oh.get();
    
    // Convert to FileBlock
    FileBlock block;
    obj.convert(block);
    
    return block;
}

} // namespace benchmark