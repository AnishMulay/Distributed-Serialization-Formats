#include <iostream>
#include "common/data_structures.h"
#include "common/serializer_interface.h"

int main() {
    std::cout << "Serialization Format Benchmark" << std::endl;
    std::cout << "==============================" << std::endl;
    
    // Create a sample FileMetadata object
    benchmark::FileMetadata metadata;
    metadata.name = "example.txt";
    metadata.path = "/home/user/example.txt";
    metadata.size = 1024;
    metadata.created_at = std::time(nullptr);
    metadata.last_modified = std::time(nullptr);
    metadata.tags = {"document", "text"};
    metadata.permissions = 0644;
    metadata.owner = "user";
    metadata.group = "users";
    
    std::cout << "Created sample metadata for file: " << metadata.name << std::endl;
    std::cout << "Size: " << metadata.size << " bytes" << std::endl;
    
    return 0;
}