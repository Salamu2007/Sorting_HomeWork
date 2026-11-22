#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

typedef enum {
    INPUT_RANDOM = 1,
    INPUT_SORTED = 2,
    INPUT_REVERSE = 3,
    INPUT_MANY_DUPLICATES = 4
} InputType;

int *generateArray(size_t n, InputType type, unsigned int seed);
int *copyArray(const int *src, size_t n);
void printArray(const int *arr, size_t n, size_t max_items);

#endif
