/* ========================================================================= *
 * BubbleSort
 * Implementation of the BubbleSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include "Sort.h"


void sort(int* array, size_t length) {
    // Nothing to do
    if (array == NULL || length <= 1) {
        return;
    }

    // Sort
    for (size_t i = 0; i < length; i++) {
        for (size_t j = i; j < length; j++) {
            if (array[i] > array[j]) {
                // Swap array[i] and array[j]
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}
