#pragma once

#include "common/serializer_interface.h"
#include <msgpack.hpp>

namespace benchmark {

class MessagePackSerializer : public SerializerInterface {
public:
    std::string format_name() const override {
        return "MessagePack";
    }
    
    std::vector<uint8_t> serialize_metadata(const FileMetadata& metadata) override;
    FileMetadata deserialize_metadata(const std::vector<uint8_t>& data) override;
    
    std::vector<uint8_t> serialize_block(const FileBlock& block) override;
    FileBlock deserialize_block(const std::vector<uint8_t>& data) override;
};

} // namespace benchmark

// MessagePack adapters must be in the global msgpack namespace
namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

template<>
struct convert<benchmark::FileMetadata> {
    msgpack::object const& operator()(msgpack::object const& o, benchmark::FileMetadata& v) const {
        if (o.type != msgpack::type::ARRAY) throw msgpack::type_error();
        if (o.via.array.size != 9) throw msgpack::type_error();

        o.via.array.ptr[0].convert(v.name);
        o.via.array.ptr[1].convert(v.path);
        o.via.array.ptr[2].convert(v.size);
        o.via.array.ptr[3].convert(v.created_at);
        o.via.array.ptr[4].convert(v.last_modified);
        o.via.array.ptr[5].convert(v.tags);
        o.via.array.ptr[6].convert(v.permissions);
        o.via.array.ptr[7].convert(v.owner);
        o.via.array.ptr[8].convert(v.group);
        return o;
    }
};

template<>
struct pack<benchmark::FileMetadata> {
    template <typename Stream>
    msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, const benchmark::FileMetadata& v) const {
        o.pack_array(9);
        o.pack(v.name);
        o.pack(v.path);
        o.pack(v.size);
        o.pack(v.created_at);
        o.pack(v.last_modified);
        o.pack(v.tags);
        o.pack(v.permissions);
        o.pack(v.owner);
        o.pack(v.group);
        return o;
    }
};

template<>
struct convert<benchmark::FileBlock> {
    msgpack::object const& operator()(msgpack::object const& o, benchmark::FileBlock& v) const {
        if (o.type != msgpack::type::ARRAY) throw msgpack::type_error();
        if (o.via.array.size != 4) throw msgpack::type_error();

        o.via.array.ptr[0].convert(v.block_id);
        o.via.array.ptr[1].convert(v.offset);
        o.via.array.ptr[2].convert(v.data);
        o.via.array.ptr[3].convert(v.checksum);
        return o;
    }
};

template<>
struct pack<benchmark::FileBlock> {
    template <typename Stream>
    msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, const benchmark::FileBlock& v) const {
        o.pack_array(4);
        o.pack(v.block_id);
        o.pack(v.offset);
        o.pack(v.data);
        o.pack(v.checksum);
        return o;
    }
};

} // namespace adaptor
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack