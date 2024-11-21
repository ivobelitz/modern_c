#include <stdio.h>
#include <stdlib.h>

void merge(size_t n, double source[n], double dest[n], size_t start, size_t mid, size_t end) {
    size_t i = start;
    size_t j = mid;
    for (size_t k = start; k < end; k++) {
        if (i < mid && (j >= end || source[i] <= source[j])) {
            dest[k] = source[i];
            i++;
        } else {
            dest[k] = source[j];
            j++;
        }
    }
}

void mergeSortHelper(size_t n, double source[n], double dest[n], size_t start, size_t end) {
    if (end < start || end - start < 2) {
        return;
    }

    size_t mid = start + (end - start) / 2;
    mergeSortHelper(n, dest, source, start, mid);
    mergeSortHelper(n, dest, source, mid, end);
    merge(n, source, dest, start, mid, end);
}

void mergeSort(size_t n, double array[n]) {
    double workspace[n];
    for (size_t i = 0; i < n; i++) {
        workspace[i] = array[i];
    }
    mergeSortHelper(n, workspace, array, 0, n);
}

size_t partition(size_t n, double arr[n], int16_t lo, int16_t hi) {
    double pivot = arr[hi];
    size_t i = lo;
    for (size_t j = lo; j < hi; j++) {
        if (arr[j] <= pivot) {
            // Swap arr[i] with arr[j]
            double temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    // Swap pivot with last element
    double temp = arr[i];
    arr[i] = arr[hi];
    arr[hi] = temp;
    return i;
}

void quickSort(size_t n, double arr[n], int16_t lo, int16_t hi) {
    if (lo >= hi || lo < 0 || hi - lo < 1) {
        return;
    }

    // Partition array and get the pivot index
    size_t p = partition(n, arr, lo, hi);

    // Sort the two partitions
    quickSort(n, arr, lo, p - 1);
    quickSort(n, arr, p + 1, hi);
}

static size_t const ARR_SIZE = 20;
static size_t const MAX_NUMBER = 100;

int main(void) {
    double array[ARR_SIZE];
    for (size_t i = 0; i < ARR_SIZE; i++) {
        array[i] = rand() % MAX_NUMBER;
    }

    // mergeSort(ARR_SIZE, array);
    quickSort(ARR_SIZE, array, 0, ARR_SIZE - 1);

    for (size_t i = 0; i < ARR_SIZE; i++) {
        printf("array[%zu] = %f\n", i, array[i]);
    }
    return EXIT_SUCCESS;
}