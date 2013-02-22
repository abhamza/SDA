#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#include "Array.h"
#include "Sort.h"


/* ------------------------------------------------------------------------- *
 * The main function.
 * ------------------------------------------------------------------------- */
int main(void) {
    // Reset the random number generator
    srand(time(NULL));

    // Create a random array
    size_t length = 100;
    int* array = createRandomArray(length);

    // Sort
    struct timeval start, end;
    gettimeofday(&start, NULL);
    sort(array, length);
    gettimeofday(&end, NULL);

    // Print time
    printf("Time = %lu µs\n", 10000 * (end.tv_sec - start.tv_sec)
                              + (end.tv_usec - start.tv_usec));

    // Delete array
    free(array);

    return 0;
}
