#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

//bubble sort
int* bubblesort(int arr[], int N) {
    int i, j, temp;
    int swapped;
    for (i = 0; i < N - 1; i++) {
        swapped = 0;
        for (j = 0; j < N - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
    return arr;
}  

// Selection sort
int* selectionsort(int arr[], int N) {
    int i, j, temp, minIndex;
    for (i = 0; i < N - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < N; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
    return arr;
}

// Insertion sort
int* insertionsort(int arr[], int N) {
    int position, i, temp;
    for (i = 1; i < N; i++) {
        temp = arr[i];
        position = i;
        while (position > 0 && arr[position - 1] > temp) {
            arr[position] = arr[position - 1];
            position--;
        }
        if (position != i) {
            arr[position] = temp;
        }
    }
    return arr;
}

// Merge sort
static void merge_parts(int tab[], int start, int mid, int end) {
    int size = end - start + 1;
    int *tempTab = (int*)malloc((size_t)size * sizeof(int));
    if (!tempTab) return;

    int l1 = start;
    int l2 = mid + 1;
    int k = 0;

    while (l1 <= mid && l2 <= end) {
        if (tab[l1] <= tab[l2]) {
            tempTab[k++] = tab[l1++];
        } else {
            tempTab[k++] = tab[l2++];
        }
    }
    while (l1 <= mid) {
        tempTab[k++] = tab[l1++];
    }
    while (l2 <= end) {
        tempTab[k++] = tab[l2++];
    }

    for (int i = 0; i < size; i++) {
        tab[start + i] = tempTab[i];
    }

    free(tempTab);
}


// Recursive function for mergesort
static void mergesort_rec(int tab[], int start, int end) {
    if (start >= end) return;
    int mid = start + (end - start) / 2;
    mergesort_rec(tab, start, mid);
    mergesort_rec(tab, mid + 1, end);
    merge_parts(tab, start, mid, end);
}

int* mergesort(int tab[], int N) {
    if (tab && N > 1) {
        mergesort_rec(tab, 0, N - 1);
    }
    return tab;
}

//quick sort
static int partition_last(int tab[], int low, int high) {
    int pivot = tab[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++) {
        if (tab[j] <= pivot) {
            i++;
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
        }
    }
    temp = tab[i + 1];
    tab[i + 1] = tab[high];
    tab[high] = temp;
    return i + 1;
}

static void quicksort_rec(int tab[], int low, int high) {
    if (low < high) {
        int pivot = partition_last(tab, low, high);
        quicksort_rec(tab, low, pivot - 1);
        quicksort_rec(tab, pivot + 1, high);
    }
}

int* quicksort(int tab[], int N) {
    if (tab && N > 1) {
        quicksort_rec(tab, 0, N - 1);
    }
    return tab;
}


