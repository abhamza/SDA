/* ------------------------------------------------------------------------- *
 * Sort
 * An interface to a generic sort algorithm.
 * ------------------------------------------------------------------------- */

#ifndef _SORT_H_
# define _SORT_H_

# include <stddef.h>
# include <time.h>
# include "LinkedList.h"

/* ------------------------------------------------------------------------- *
 * Sort an array of integers.
 *
 * PARAMETERS
 * array        Array to sort
 * length       Number of elements in the array
 *
 * RETURN
 * 0            In case of success
 * -1           If an error has occured
 * ------------------------------------------------------------------------- */
int Sort(int* array, size_t length);
/* We exceptionally use an upper-case first letter to avoid confusion
 * with the standard "sort" function. A cleaner solution should be
 * to use a namespace */

/* ------------------------------------------------------------------------- *
 * Sort the element of a linked list.
 *
 * PARAMETERS
 * list         Pointer to the first element of a list
 *
 * RETURN
 * list         Pointer to the first element of the sorted linked list (NULL
 *              in case of error)
 * ------------------------------------------------------------------------- */
LinkedList* sortLinkedList(LinkedList* list);

#endif // !_SORT_H_
