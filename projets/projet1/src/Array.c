/* ========================================================================= *
 * Array generator
 * Implementation of the Array generator interface
 * ========================================================================= */

#include <stdlib.h>
#include <stddef.h>

#include "Array.h"
#include "Sort.h"


int* createSortedArray(size_t length) {
    int* array = (int*) malloc(length * sizeof(int));

    if (array == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < length; i++) {
        array[i] = i;
    }

    return array;
}

int* createRandomArray(size_t length) {
    int* array = createSortedArray(length);

    if (array == NULL) {
        return NULL;
    }

    for (size_t i = length - 1; i > 0; i--) {
        size_t j = rand() % (i + 1);
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    return array;
}

static int __compare(const void* a, const void* b);

static int __compare(const void* a, const void* b){
  return *(int*)a - *(int*)b;
}

int* createRandomBlockArray(size_t length, size_t k) {
    int* randomBlockArray = (int*) malloc(length * sizeof(int));
    int* randomArray = createRandomArray(length);
    int* blocks = createRandomArray(k);

    if (randomBlockArray == NULL ||
        randomArray == NULL ||
        blocks == NULL) {
        if (randomBlockArray != NULL) free(randomBlockArray);
        if (randomArray != NULL) free(randomArray);
        if (blocks != NULL) free(blocks);

        return NULL;
    }

    size_t j = 0;

    for (size_t b = 0; b < k; b++) {
        size_t start = length * blocks[b] / k;
        size_t end = length * (blocks[b] + 1) / k;
        size_t blockSize = end - start;

        for (size_t i = start; i < end; i++) {
            randomBlockArray[j++] = randomArray[i];
        }

        qsort(randomBlockArray + j - blockSize, blockSize,
              sizeof(int), __compare);
    }

    free(randomArray);
    free(blocks);

    return randomBlockArray;
}
