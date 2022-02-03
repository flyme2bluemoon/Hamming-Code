#include <stdlib.h>

#include "hamming.h"

u_int8_t get_parity(u_int64_t message)
{
    u_int8_t parity = 0;
    u_int8_t bit;
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        bit = (message >> (MESSAGE_SIZE - 1 - i)) & 1ULL;
        if (bit == 1) {
            parity ^= i;
        }
    }

    return parity;
}
