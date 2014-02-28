/* ------------------------------------------------------------------------- *
 * BubbleSort
 * Implementation of the BubbleSort algorithm.
 * ------------------------------------------------------------------------- */

#include "Sort.h"

/* Prototypes */
void swap(int* array, size_t firstIndex, size_t secondIndex);

/* Functions */
void swap(int* array, size_t firstIndex, size_t secondIndex) {
    int tmp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = tmp;
}

int Sort(int* array, size_t length) {
    if (length <= 0 || !array) {
        return -1;
    }

    for (size_t i = 0; i < length; ++i) {
        for (size_t j = i; j < length; ++j) {
            if (array[i] > array[j]) {
                swap(array, i, j);
            }
        }
    }

    return 0;
}
