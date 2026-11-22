#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "benchmark.h"
#include "utils.h"

static double bytesToMB(size_t bytes) {
    return (double)bytes / (1024.0 * 1024.0);
}

static double estimateAlgorithmMemoryMB(const char *algo_name, int n) {
    size_t array_bytes = (size_t)n * sizeof(int);
    size_t extra_bytes = 0;

    if (algo_name[0] == 'M' || algo_name[0] == 'm') {
        extra_bytes = array_bytes;
    }

    return bytesToMB(array_bytes + extra_bytes);
}

BenchmarkResult benchmarkSingleAlgorithm(const char *name,
                                         SortAlgorithmFunc sortFn,
                                         const int *original,
                                         int n,
                                         int runs) {
    BenchmarkResult res;
    res.name = name;
    res.avg_time_ms = 0.0;
    res.memory_mb = estimateAlgorithmMemoryMB(name, n);
    res.rank = 0;

    if (!original || n <= 0 || runs <= 0 || !sortFn) {
        res.avg_time_ms = -1.0;
        return res;
    }

    double total_ms = 0.0;

    for (int r = 0; r < runs; r++) {
        int *work = copyArray(original, n);
        if (!work) {
            res.avg_time_ms = -1.0;
            return res;
        }

        clock_t start = clock();
        sortFn(work, n);
        clock_t end = clock();

        double elapsed_ms = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
        total_ms += elapsed_ms;

        free(work);
    }

    res.avg_time_ms = total_ms / runs;
    return res;
}

static void assignRanks(BenchmarkResult results[], int count) {
    for (int i = 0; i < count; i++) {
        int rank = 1;
        for (int j = 0; j < count; j++) {
            if (results[j].avg_time_ms >= 0 &&
                results[i].avg_time_ms >= 0 &&
                results[j].avg_time_ms < results[i].avg_time_ms) {
                rank++;
            }
        }
        results[i].rank = rank;
    }
}

void printComparisonTable(int n, BenchmarkResult results[], int count) {
    assignRanks(results, count);

    printf("\n+----------------------+------------+---------------+---------------+------+\n");
    printf("| Algorithm            | Array Size | Time (ms)     | Memory (MB)   | Rank |\n");
    printf("+----------------------+------------+---------------+---------------+------+\n");

    for (int i = 0; i < count; i++) {
        if (results[i].avg_time_ms < 0) {
            printf("| %-20s | %-10d | %-13s | %-13s | %-4s |\n",
                   results[i].name, n, "N/A", "N/A", "-");
        } else {
            printf("| %-20s | %-10d | %-13.3f | %-13.4f | %-4d |\n",
                   results[i].name, n, results[i].avg_time_ms,
                   results[i].memory_mb, results[i].rank);
        }
    }

    printf("+----------------------+------------+---------------+---------------+------+\n");
}

void compareAlgorithms(SortAlgorithmFunc algos[5], const char *names[5],
                      int n, InputType input_type, unsigned int seed, int runs) {
    int *base = generateArray((size_t)n, input_type, seed);
    if (!base) {
        printf("Memory allocation failed for size %d.\n", n);
        return;
    }

    BenchmarkResult results[5];
    for (int i = 0; i < 5; i++) {
        results[i] = benchmarkSingleAlgorithm(names[i], algos[i], base, n, runs);
    }

    printComparisonTable(n, results, 5);
    free(base);
}

void compareAllSizes(SortAlgorithmFunc algos[5], const char *names[5],
                     InputType input_type, unsigned int seed, int runs) {
    int sizes[] = {1000, 5000, 10000, 50000, 100000};
    int num_sizes = (int)(sizeof(sizes) / sizeof(sizes[0]));

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
        int *base = generateArray(n, input_type, seed + (unsigned int)s);
        if (!base) {
            printf("Memory allocation failed for size %d.\n", n);
            continue;
        }

        BenchmarkResult results[5];
        for (int a = 0; a < 5; a++) {
            results[a] = benchmarkSingleAlgorithm(names[a], algos[a], base, n, runs);
        }

        printComparisonTable(n, results, 5);
        free(base);
    }
}