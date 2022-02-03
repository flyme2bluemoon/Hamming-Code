#include <stdio.h>
#include <stdlib.h>

#include "hamming.h"

int main()
{
    FILE* corrupted = fopen("corrupted.txt", "r");
    if (!corrupted) {
        printf("Unable to open corrupted.txt");
        return 1;
    }

    FILE* recovered = fopen("recovered.txt", "w");
    if (!recovered) {
        printf("Unable to open recovered.txt");
        return 1;
    }

    u_int64_t message;
    u_int8_t parity;
    for (int i = 0; i < MESSAGE_COUNT; i++) {
        fscanf(corrupted, "%llx", &message);
        parity = get_parity(message);
        message ^= 1ULL << (MESSAGE_SIZE - 1 - parity);
        fprintf(recovered, "%llx\n", message);
    }

    fclose(corrupted);
    fclose(recovered);

    return 0;
}
