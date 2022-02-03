#include <stdio.h>
#include <stdlib.h>

#include "hamming.h"

int main()
{
    FILE* corrupted = fopen("corrupted.txt", "r");
    if (!corrupted) {
        printf("Unable to open corrupted.txt\n");
        return 1;
    }

    FILE* recovered = fopen("recovered.txt", "w");
    if (!recovered) {
        printf("Unable to open recovered.txt\n");
        return 1;
    }

    uint64_t message;
    uint8_t parity;
    for (int i = 0; i < MESSAGE_COUNT; i++) {
        if (fscanf(corrupted, "%lx", &message) == EOF) {
            break;
        }
        parity = get_parity(message);
        message ^= 1ULL << (MESSAGE_SIZE - 1 - parity);
        fprintf(recovered, "%lx\n", message);
    }

    fclose(corrupted);
    fclose(recovered);

    return 0;
}
