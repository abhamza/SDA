#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Array.h"
#include "Sort.h"


/* ------------------------------------------------------------------------- *
 * The main function.
 *
 * Generate events
 * Sort events
 * Print CPU time used to sort events
 * ------------------------------------------------------------------------- */
int main(void) {
    // Reset the random number generator
    srand(time(NULL));

    // Create a random array
    size_t length = 10000;
    int* array = createRandomArray(length);

    // Sort
    clock_t start = clock();
    sort(array, length);
    clock_t end = clock();

    // print CPU time
    printf("CPU time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Delete array
    free(array);

    return 0;
}
