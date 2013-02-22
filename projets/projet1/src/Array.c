/* ========================================================================= *
 * Array generator
 * Implementation of the Array generator interface
 * ========================================================================= */

#include <stdlib.h>
#include <stddef.h>
#include "Array.h"


int* createSortedArray(size_t length) {
    int* array = (int*) malloc(length * sizeof(int));

    for (size_t i = 0; i < length; i++) {
        array[i] = i;
    }

    return array;
}

int* createRandomArray(size_t length) {
    int* array = createSortedArray(length);

    for (size_t i = length - 1; i > 0; i--) {
        size_t j = rand() % (i + 1);
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    return array;
}
