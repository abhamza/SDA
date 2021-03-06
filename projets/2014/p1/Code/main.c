#include <stdlib.h>
#include <stdio.h>

#include "Sort.h"

/* Prototypes */

/* ------------------------------------------------------------------------- *
 * Compute the CPU time (in seconds) used by the Sort function.
 *
 * PARAMETERS
 * array        Array to sort
 * length       Number of elements in the array
 *
 * RETURN
 * seconds      The number of seconds used by Sort
 * ------------------------------------------------------------------------- */
double cpuTimeUsedToSort(int* array, size_t length);

/* ------------------------------------------------------------------------- *
 * Generate an array of random int.
 *
 * PARAMETERS
 * length        Length of the array
 *
 * RETURN
 * array         The random array
 * ------------------------------------------------------------------------- */
int* createRandomIntArray(size_t length);

/* Functions */
double cpuTimeUsedToSort(int* array, size_t length) {
    clock_t start = clock();

    if (Sort(array, length) == -1) {
        return -1.0;
    }
    else {
        return ((double) (clock() - start)) / CLOCKS_PER_SEC;
    }
}

int* createRandomIntArray(size_t length) {
    int* array = malloc(length * sizeof(int));

    if (array == NULL) {
        return NULL;
    }

    for (size_t i = 0 ; i < length; ++i) {
        array[i] = rand();
    }

    return array;
}


/* ------------------------------------------------------------------------- *
 * Main
 * ------------------------------------------------------------------------- */
int main(void) {
    srand(time(NULL));

    size_t sizeArray = 10000;
    printf("Size of the array: %d\n", (int) sizeArray);
    int* array = createRandomIntArray(sizeArray);

    const double sec = cpuTimeUsedToSort(array, sizeArray);
    printf("CPU Time: %f\n", sec);

    free(array);

    return 0;
}
