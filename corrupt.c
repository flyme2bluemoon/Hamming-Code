#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hamming.h"

int main()
{
    srandom(time(NULL));

    FILE* original = fopen("messages.txt", "r");
    if (!original) {
        printf("Unable to open messages.txt");
        return 1;
    }

    FILE* corrupted = fopen("corrupted.txt", "w");
    if (!corrupted) {
        printf("Unable to open corrupted.txt");
        return 1;
    }

    uint64_t message;
    unsigned int flip_index;
    for (int i = 0; i < MESSAGE_COUNT; i++) {
        fscanf(original, "%llx", &message);
        flip_index = random() % (MESSAGE_SIZE - 1);
        message ^= 1ULL << flip_index;
        fprintf(corrupted, "%llx\n", message);
    }

    fclose(original);
    fclose(corrupted);

    return 0;
}
