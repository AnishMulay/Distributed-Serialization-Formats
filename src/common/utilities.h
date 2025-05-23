#pragma once
#include <vector>
#include <cstdint>

namespace benchmark {
    uint32_t calculate_checksum(const std::vector<uint8_t>& data);
}