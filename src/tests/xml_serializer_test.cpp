#include <iostream>
#include <cassert>
#include "formats/xml/xml_serializer.h"
#include "common/test_data_generator.h"

using namespace benchmark;

void test_metadata_serialization_deserialization() {
    XmlSerializer serializer;
    TestDataGenerator generator;
    
    // Generate a sample metadata
    FileMetadata original = generator.generate_metadata();
    
    // Serialize
    std::vector<uint8_t> serialized = serializer.serialize_metadata(original);
    
    // Print the serialized data as string
    std::cout << "Serialized metadata (XML): " << std::string(serialized.begin(), serialized.end()) << std::endl;
    
    // Deserialize
    FileMetadata deserialized = serializer.deserialize_metadata(serialized);
    
    // Verify that the deserialized object equals the original
    assert(deserialized.name == original.name);
    assert(deserialized.path == original.path);
    assert(deserialized.size == original.size);
    assert(deserialized.created_at == original.created_at);
    assert(deserialized.last_modified == original.last_modified);
    assert(deserialized.tags == original.tags);
    assert(deserialized.permissions == original.permissions);
    assert(deserialized.owner == original.owner);
    assert(deserialized.group == original.group);
    
    std::cout << "Metadata serialization/deserialization test passed!" << std::endl;
}

void test_block_serialization_deserialization() {
    XmlSerializer serializer;
    TestDataGenerator generator;
    
    // Generate sample blocks of different sizes
    std::vector<size_t> sizes = {64, 1024, 4096};
    
    for (size_t size : sizes) {
        // Generate a sample block
        FileBlock original = generator.generate_block(size);
        
        // Serialize
        std::vector<uint8_t> serialized = serializer.serialize_block(original);
        
        // Print info about the serialized data
        std::cout << "Serialized block of size " << size << " bytes to " 
                  << serialized.size() << " bytes (XML)" << std::endl;
        
        // Deserialize
        FileBlock deserialized = serializer.deserialize_block(serialized);
        
        // Verify that the deserialized object equals the original
        assert(deserialized.block_id == original.block_id);
        assert(deserialized.offset == original.offset);
        assert(deserialized.data == original.data);
        assert(deserialized.checksum == original.checksum);
    }
    
    std::cout << "Block serialization/deserialization test passed!" << std::endl;
}

int main() {
    std::cout << "Running XML serializer tests..." << std::endl;
    
    test_metadata_serialization_deserialization();
    test_block_serialization_deserialization();
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}