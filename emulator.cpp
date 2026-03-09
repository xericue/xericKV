#include <cstdint>

class Chip8 {
    public:
    uint8_t registers[16] {}; // cuz its 8 bits
    uint8_t memory_space[4096] {}; // 4096 bits in memory
    uint16_t index_register {};
    
};


int main() {

    return 0;
}