#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// 1. generate an array of integers based on the specified type and size
int* generateArray(size_t n, InputType type, unsigned int seed) {
    int *arr = (int*)malloc(n * sizeof(int));
    if (!arr) return NULL;

    srand(seed);
    for (size_t i = 0; i < n; i++) {
        switch (type) {
            case INPUT_RANDOM:
                arr[i] = rand() % 1000000;
                break;
            case INPUT_SORTED:
                arr[i] = (int)i;
                break;
            case INPUT_REVERSE:
                arr[i] = (int)(n - i);
                break;
            case INPUT_MANY_DUPLICATES:
                arr[i] = rand() % 10;
                break;
            default:
                arr[i] = rand() % 1000000;
                break;
        }
    }
    return arr;
}

// 2. copy an array of integers
int* copyArray(const int *src, size_t n) {
    if (!src) return NULL;
    int *dst = (int*)malloc(n * sizeof(int));
    if (!dst) return NULL;

    for (size_t i = 0; i < n; i++) {
        dst[i] = src[i];
    }
    return dst;
}

// 3. display elements of an array (limit the number of items to prevent overflow on the screen)
void printArray(const int *arr, size_t n, size_t max_items) {
    if (!arr) return;
    size_t limit = (n < max_items) ? n : max_items;

    printf("[");
    for (size_t i = 0; i < limit; i++) {
        printf("%d", arr[i]);
        if (i + 1 < limit) printf(", ");
    }
    if (n > max_items) {
        printf(", ... (%zu elements total)", n);
    }
    printf("]\n");
}