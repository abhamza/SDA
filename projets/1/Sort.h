/***********************************************************************
 * Sort
 * An interface to a generic sort algorithm.
 ***********************************************************************/

#ifndef _SORT_H_
# define _SORT_H_

# include <stddef.h>
# include <time.h>

/***********************************************************************
 * Sort the elements in an array.
 * The elements are compared using a comparison function.
 *
 * PARAMETERS
 * array        The generic array to sort
 * length       Number of elements in the array
 * comparator   Pointer to a comparison function between two elements of the
 *              array. It returns a negative integer if the first element is
 *              less than the second, 0 if both are equal, and a positive
 *              integer otherwise.
 ***********************************************************************/
void Sort(const void** array, size_t length, int (*comparator)(const void*, const void*));
/* We exceptionally use an upper-case first letter to avoid confusion
 * with the standard "sort" function. A cleaner solution should be
 * to use a namespace */

#endif // !_SORT_H_
