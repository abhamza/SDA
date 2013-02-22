/* ========================================================================= *
 * Array generator
 * ========================================================================= */

#ifndef _ARRAY_H_
# define _ARRAY_H_

#include <stddef.h>


/* ------------------------------------------------------------------------- *
 * Create a sorted array of integers (from 0 to length-1).
 *
 * The array must later be deleted by calling free().
 *
 * PARAMETERS
 * length       Number of elements in the array
 *
 * RETURN
 * array        A new array of integers
 * ------------------------------------------------------------------------- */
int* createSortedArray(size_t length);

/* ------------------------------------------------------------------------- *
 * Create a random array of integers (from 0 to length-1).
 *
 * The array must later be deleted by calling free().
 *
 * PARAMETERS
 * length       Number of elements in the array
 *
 * RETURN
 * array        A new array of integers
 * ------------------------------------------------------------------------- */
int* createRandomArray(size_t length);

/* ------------------------------------------------------------------------- *
 * Create a random array of integers (from 0 to length-1), with k pre-sorted
 * blocks.
 *
 * The array must later be deleted by calling free().
 *
 * PARAMETERS
 * length       Number of elements in the array
 * k            Number of pre-sorted blocks
 *
 * RETURN
 * array        A new array of integers
 * ------------------------------------------------------------------------- */
int* createRandomBlockArray(size_t length, size_t k);


#endif // !_ARRAY_H_
