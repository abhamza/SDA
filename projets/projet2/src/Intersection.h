/* ========================================================================= *
 * Intersection
 * ========================================================================= */

#ifndef _INTERSECTION_H_
# define _INTERSECTION_H_

#include <stdbool.h>
#include "Array.h"

/* ------------------------------------------------------------------------- *
 * Return a new Array object that contains the common elements of two Array
 * objects. To compare elements, the function use the compareFunction()
 * provided by the arrays. Therefore, the elements of the two Array must be
 * compatible in the sense of compareFunction().
 *
 * The new Array object must later be deleted by calling
 * freeArray(array, false). Note that the function copies adresses of common
 * elements. It doesn't clone the content of common elements.
 *
 * PARAMETERS
 * array1       The first container of elements
 * array2       The second container of elements
 *
 * RETURN
 * Array        A new Array object that contains the common elements
 * ------------------------------------------------------------------------- */
Array* getIntersection(const Array* array1, const Array* array2);

#endif // !_INTERSECTION_H_
