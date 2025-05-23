#include "common/utilities.h"

namespace benchmark {
    uint32_t calculate_checksum(const std::vector<uint8_t>& data) {
        const uint32_t MOD_ADLER = 65521;
        uint32_t a = 1, b = 0;
        for (uint8_t byte : data) {
            a = (a + byte) % MOD_ADLER;
            b = (b + a) % MOD_ADLER;
        }
        return (b << 16) | a;
    }
}