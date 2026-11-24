# Title
Sorting Algorithms & Performance Benchmark

# Full Name 
Boukhendeg Mouhammed Islam 
Hadj Mouhammed Wassim

# group 
DD2 Gr1

# academy year
2026/2027

# Language & Version
C11 (ISO/IEC 9899:2011)

# The Library used
### stdio.h
Used for standard input/output operations—displaying the interactive menu, sorting results, and comparison tables (`printf`), reading user choices and array sizes (`scanf`), and exporting benchmark results to CSV files (`fopen`, `fprintf`, `fclose`).

### stdlib.h
Used for dynamic memory allocation (`malloc`, `free`) on the heap to handle large arrays (such as 100,000+ elements) safely, and for generating reproducible random test data (`srand`, `rand` with a fixed seed)

### time.h
Used to measure execution time via `clock()` and `CLOCKS_PER_SEC` in milliseconds so we can accurately compare algorithm speed across different input sizes

# Instructions to install
click run the file and will work it
or write this gcc -Wall -Wextra -O2 src/*.c -I. -o sorting_benchmark

# Algorithm Descriptions & Complexities

## Bubble Sort: 
Repeatedly steps through the array, compares adjacent elements, and swaps them if they are in the wrong order. With an early-exit flag (changed), it stops early when a pass makes no swaps.
Time: Best O(n) (already sorted with early exit) | Average O(n^2) | Worst O(n^2)
Space: O(1) auxiliary (in-place)

## Selection Sort: 
Divides the array into a sorted left part and an unsorted right part, repeatedly finding the minimum element from the unsorted part and placing it at the end of the sorted part.
Time: Best O(n^2) | Average O(n^2) | Worst O(n^2)
Space: O(1) auxiliary (in-place)

## Insertion Sort: 
Builds the sorted array one element at a time by taking the next element (key) and shifting larger elements to the right until finding its proper position.
Time: Best O(n) (already sorted) | Average O(n^2) | Worst O(n^2)
Space: O(1) auxiliary (in-place)

## Merge Sort: 
Uses a divide-and-conquer approach—splits the array in half recursively, sorts each half, and merges the sorted halves back together.
Time: Best O(n \log n) | Average O(n \log n) | Worst O(n \log n)
Space: O(n) auxiliary (uses temporary subarrays during merging, plus O(\log n) recursion stack)

## Quick Sort: 
Selects a pivot element (the last element high in your implementation), partitions elements around the pivot so smaller elements go before it and larger ones after it, then recursively sorts both sides.
Time: Best O(n \log n) | Average O(n \log n) | Worst O(n^2) (unbalanced partitions, e.g., sorted/reverse input with last-element pivot)
Space: O(\log n) average recursion stack (O(n) worst-case stack depth)

# The comparison results

## array 1000 element

+----------------------+------------+---------------+---------------+------+
| Algorithm            | Array Size | Time (ms)     | Memory (MB)   | Rank |
+----------------------+------------+---------------+---------------+------+
| Bubble Sort          | 1000       | 6.200         | 0.0038        | 5    |
| Selection Sort       | 1000       | 1.800         | 0.0038        | 4    |
| Insertion Sort       | 1000       | 1.000         | 0.0038        | 3    |
| Merge Sort           | 1000       | 0.200         | 0.0076        | 1    |
| Quick Sort           | 1000       | 0.200         | 0.0038        | 1    |
+----------------------+------------+---------------+---------------+------+

## array 5000 element

+----------------------+------------+---------------+---------------+------+
| Algorithm            | Array Size | Time (ms)     | Memory (MB)   | Rank |
+----------------------+------------+---------------+---------------+------+
| Bubble Sort          | 5000       | 96.400        | 0.0191        | 5    |
| Selection Sort       | 5000       | 39.600        | 0.0191        | 4    |
| Insertion Sort       | 5000       | 20.600        | 0.0191        | 3    |
| Merge Sort           | 5000       | 1.400         | 0.0381        | 2    |
| Quick Sort           | 5000       | 0.600         | 0.0191        | 1    |
+----------------------+------------+---------------+---------------+------+

## array 10000 element

+----------------------+------------+---------------+---------------+------+
| Algorithm            | Array Size | Time (ms)     | Memory (MB)   | Rank |
+----------------------+------------+---------------+---------------+------+
| Bubble Sort          | 10000      | 386.800       | 0.0381        | 5    |
| Selection Sort       | 10000      | 155.400       | 0.0381        | 4    |
| Insertion Sort       | 10000      | 82.800        | 0.0381        | 3    |
| Merge Sort           | 10000      | 3.200         | 0.0763        | 2    |
| Quick Sort           | 10000      | 1.200         | 0.0381        | 1    |
+----------------------+------------+---------------+---------------+------+

## array 50000 element

+----------------------+------------+---------------+---------------+------+
| Algorithm            | Array Size | Time (ms)     | Memory (MB)   | Rank |
+----------------------+------------+---------------+---------------+------+
| Bubble Sort          | 50000      | 11046.600     | 0.1907        | 5    |
| Selection Sort       | 50000      | 4882.600      | 0.1907        | 4    |
| Insertion Sort       | 50000      | 2378.600      | 0.1907        | 3    |
| Merge Sort           | 50000      | 16.800        | 0.3815        | 2    |
| Quick Sort           | 50000      | 8.200         | 0.1907        | 1    |
+----------------------+------------+---------------+---------------+------+

## array 100000 element

+----------------------+------------+---------------+---------------+------+
| Algorithm            | Array Size | Time (ms)     | Memory (MB)   | Rank |
+----------------------+------------+---------------+---------------+------+
| Bubble Sort          | 100000     | 37724.400     | 0.3815        | 5    |
| Selection Sort       | 100000     | 15336.600     | 0.3815        | 4    |
| Insertion Sort       | 100000     | 9183.400      | 0.3815        | 3    |
| Merge Sort           | 100000     | 40.800        | 0.7629        | 2    |
| Quick Sort           | 100000     | 21.600        | 0.3815        | 1    |
+----------------------+------------+---------------+---------------+------+

## specifications of my machine

CPU: Intel(R) Core(TM) i5-6200U CPU @ 2.30GHz
Memory: 8.0 GB	Speed:	2133 MHz
Windows: 11 Pro 22H2

# Critical Analysis

## Best Algorithm by Scenario

### Large random datasets (`n >= 100,000`):
Quick Sort: is best in practice when average execution time matters most (`21.600 ms` on `100,000` random elements) while keeping memory usage low (`0.3815 MB`).

### *Guaranteed worst-case speed or stability:
Merge Sort: is ideal when consistent O(n \log n) performance is required regardless of input order, provided extra memory (`0.7629 MB`) is acceptable.

### Small or nearly sorted arrays:
Insertion Sort: works efficiently on small inputs or nearly sorted data where shifting requires minimal work and recursion overhead is avoided.

### Tight memory / minimal swaps:
Selection Sort: uses O(1) extra space and performs at most O(n) swaps, though its O(n^2) comparisons make it slow on large datasets (`15336.600 ms` at `n = 100,000`).

### Basic learning / simple checks:
Bubble Sort: is mainly useful for demonstrating adjacent swaps and early exit (`changed`), as it is the slowest on large inputs (`37724.400 ms` at `n = 100,000`).

## Do Experiments Match Theory?
**Yes.** On `100,000` random elements, O(n \log n) algorithms (**Quick Sort** at `21.600 ms` and **Merge Sort** at `40.800 ms`) vastly outperform O(n^2) algorithms (`9.18 s` to `37.72 s`), matching theoretical growth rates. **Merge Sort** also reflects its O(n) space complexity by using double the memory (`0.7629 MB` vs. `0.3815 MB`). Note that since **Quick Sort** uses the last element as pivot, its performance degrades toward O(n^2) on already-sorted or reverse-sorted inputs.

# Problems Faced & Solutions

## Invalid input handling:
 Entering non-numeric characters caused `scanf` input issues; fixed by checking the return value (`!= 1`) and clearing remaining characters with `while (getchar() != '\n');`.

## Accurate multi-run timing:
 Reusing the same array across `5` benchmark runs would measure already-sorted data after the first pass; solved by copying the original array before each run and freeing the copy afterward.

## Long wait times on large O(n^2) runs:
 Running `5` iterations of quadratic algorithms on `100,000` elements took tens of seconds per algorithm, illustrating the practical impact of O(n^2) complexity at scale.

