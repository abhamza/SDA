/***********************************************************************
 * Sort
 * An interface to a generic sort algorithm.
 ***********************************************************************/

#ifndef _SORT_H_
# define _SORT_H_

# include <stddef.h>
# include <time.h>
# include "LinkedList.h"

/***********************************************************************
 * Sort an array of integers.
 *
 * PARAMETERS
 * array        Array to sort
 * length       Number of elements in the array
 *
 * RETURN
 * 0            In case of success
 * -1           If an error has occured
 ***********************************************************************/
int Sort(int* array, size_t length);
/* We exceptionally use an upper-case first letter to avoid confusion
 * with the standard "sort" function. A cleaner solution should be
 * to use a namespace */

/***********************************************************************
 * Sort the element of a linked list.
 * The elements are compared using a comparison function.
 *
 * PARAMETERS
 * list         Pointer to the first element of a list
 * comparator   Pointer to a comparison function between two elements of the
 *              array. It returns a negative integer if the first element is
 *              less than the second, 0 if both are equal, and a positive
 *              integer otherwise.
 *
 * RETURN
 * list         Pointer to the first element of the sorted linked list (NULL 
 *              in case of error)
 ***********************************************************************/
LinkedList* sortLinkedList(LinkedList* list, int (*comparator)(const void*, const void*));

#endif // !_SORT_H_

