#include <stdio.h>
#include <stdlib.h>
#include "benchmark.h"
#include "sorting.h"
#include "utils.h"

static int readInputType(InputType *type) {
    int input_type;

    printf("Select array type:\n");
    printf("1. Random\n");
    printf("2. Sorted\n");
    printf("3. Reverse sorted\n");
    printf("4. Many duplicates\n");
    printf("Your choice: ");

    if (scanf("%d", &input_type) != 1 || input_type < INPUT_RANDOM ||
        input_type > INPUT_MANY_DUPLICATES) {
        printf("Invalid array type. Choose a number from 1 to 4.\n");
        while (getchar() != '\n');
        return 0;
    }

    *type = (InputType)input_type;
    return 1;
}

int main(void) {
    int choice;
    int n;
    InputType input_type;
    unsigned int seed = 42;
    int runs = 5;
    SortAlgorithmFunc algorithms[5] = {
        bubblesort, selectionsort, insertionsort, mergesort, quicksort
    };
    const char *names[5] = {
        "Bubble Sort", "Selection Sort", "Insertion Sort", "Merge Sort", "Quick Sort"
    };

    while (1) {
        printf("\n=== SORTING ALGORITHMS ===\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Compare all algorithms\n");
        printf("0. Exit\n");
        printf("Your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Erreur: must enter num between (0-6)!\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 0) {
            printf("exit succesful!\n");
            break;
        }

        if (choice >= 1 && choice <= 5) {
            printf("Enter array size (taille): ");
            if (scanf("%d", &n) != 1 || n <= 0) {
                printf("Erreur: Taille ghalta!\n");
                while (getchar() != '\n');
                continue;
            }

            if (!readInputType(&input_type)) {
                continue;
            }

            int *original = generateArray((size_t)n, input_type, seed);
            if (!original) {
                printf("Erreur: impossible d'allouer la memoire!\n");
                continue;
            }

            if (n <= 20) {
                printf("Avant le tri: ");
                printArray(original, (size_t)n, 20);
            }

            BenchmarkResult result = benchmarkSingleAlgorithm(
                names[choice - 1], algorithms[choice - 1], original, n, runs);

            printf("\nResultat pour %s (Taille: %d):\n", result.name, n);
            printf("- Temps moyen : %.3f ms\n", result.avg_time_ms);
            printf("- Memoire     : %.4f MB\n", result.memory_mb);
            free(original);
        } else if (choice == 6) {
            printf("Enter array size (taille): ");
            if (scanf("%d", &n) != 1 || n <= 0) {
                printf("Erreur: Taille ghalta!\n");
                while (getchar() != '\n');
                continue;
            }

            if (!readInputType(&input_type)) {
                continue;
            }

            printf("\nLancement de la comparaison (Taille: %d)...\n", n);
            compareAlgorithms(algorithms, names, n, input_type, seed, runs);
        } else {
            printf("Choix ghalet! Ekhtar bin 0 w 6.\n");
        }
    }

    return 0;
}