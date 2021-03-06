#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <limits.h>

#include "Array.h"
#include "Sort.h"


/* ------------------------------------------------------------------------- *
 * The main function.
 * ------------------------------------------------------------------------- */
int main(void) {
    size_t i = INT_MAX;
    printf("%d\n", i);

    // Reset the random number generator
    srand(time(NULL));

    // Create a random array
    size_t length = 100;
    int* array = createRandomArray(length);

    if (array == NULL) {
        printf("Erreur d'allocation.\n");
        return 1;
    }

    // Sort
    struct timeval start, end;
    gettimeofday(&start, NULL);
    sort(array, length);
    gettimeofday(&end, NULL);

    // Print time
    printf("Time = %lu µs\n", 1000000l * (end.tv_sec - start.tv_sec)
                              + (end.tv_usec - start.tv_usec));

    // Delete array
    free(array);

    return 0;
}
