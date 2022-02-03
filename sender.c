#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "hamming.h"

u_int64_t prepare_block(u_int64_t message)
{
    u_int8_t parity = get_parity(message);
    u_int8_t bit;

    for (int i = 0; i < log2(MESSAGE_SIZE); i++) {
        bit = (parity >> i) & 1ULL;
        if (bit == 1) {
            message ^= 1ULL << (int)(MESSAGE_SIZE - 1 - pow(2, i));
        }
    }

    return message;
}

int main()
{
    srandom(time(NULL));

    FILE* file = fopen("messages.txt", "w");
    if (!file) {
        printf("Unable to open messages.txt");
        return 1;
    }

    for (int i = 0; i < MESSAGE_COUNT; i++) {
        u_int64_t message = (random() << 32) + random();
        message = prepare_block(message);
        fprintf(file, "%llx\n", message);
    }

    fclose(file);

    return 0;
}