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
 * comparator   Pointer to the comparison function taking two generic
 *              values of same type than those contained in the array.
 *              It returns a negatif integer if the first argument goes
 *              before the second argument, 0 if first and second
 *              arguments are equals, and a positive integer otherwise.
 ***********************************************************************/
void Sort(const void** array, size_t length, int (*comparator)(const void*, const void*));
/* We exceptionally use an upper-case first letter to avoid confusion
 * with the standard "sort" function. A more proper solution should be
 * to use a namespace */

#endif // !_SORT_H_
