#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "utils.h"

typedef int *(*SortAlgorithmFunc)(int *, int);

typedef struct {
    const char *name;
    double avg_time_ms;
    double memory_mb;
    int rank;
} BenchmarkResult;

BenchmarkResult benchmarkSingleAlgorithm(const char *name,
                                         SortAlgorithmFunc sortFn,
                                         const int *original,
                                         int n,
                                         int runs);
void printComparisonTable(int n, BenchmarkResult results[], int count);
void compareAlgorithms(SortAlgorithmFunc algos[5],
                      const char *names[5],
                      int n,
                      InputType input_type,
                      unsigned int seed,
                      int runs);
void compareAllSizes(SortAlgorithmFunc algos[5],
                     const char *names[5],
                     InputType input_type,
                     unsigned int seed,
                     int runs);

#endif
