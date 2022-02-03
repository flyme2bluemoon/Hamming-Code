#ifndef HAMMING_H
#define HAMMING_H
#include <stdint.h>

#define MESSAGE_COUNT 1000
#define MESSAGE_SIZE 64

uint8_t get_parity(uint64_t message);

#endif
