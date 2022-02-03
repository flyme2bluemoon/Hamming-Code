#include <stdlib.h>

#include "hamming.h"

uint8_t get_parity(uint64_t message)
{
    uint8_t parity = 0;
    uint8_t bit;
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        bit = (message >> (MESSAGE_SIZE - 1 - i)) & 1ULL;
        if (bit == 1) {
            parity ^= i;
        }
    }

    return parity;
}
