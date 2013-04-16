/* ========================================================================= *
 * Array
 * An Array is a generic object to store data into a vector.
 *
 * An Array is composed of a vector $values$ and the length of the vector.
 * ========================================================================= */

#ifndef _ARRAY_H_
# define _ARRAY_H_

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

/* Structure */
typedef struct Array_t
{
    void** values;
    size_t length;
} Array;

/* ------------------------------------------------------------------------- *
 * Create an Array object from the content of the file $fileName$. Each line
 * of $fileName$ is stored as an element of the Array object.
 *
 * The Array object must later be deleted by calling freeArray().
 *
 * PARAMETER
 * fileName         Name of a file
 *
 * RETURN
 * Array            A new pointer to an Array object
 * NULL             If an error has occured. The function produces an error
 *                  message on the standard error output.
 * ------------------------------------------------------------------------- */
Array* createArrayFromFile(const char* fileName);

/* ------------------------------------------------------------------------- *
 * Free the allocated memory of the Array object $array$. If the flag
 * $deleteElements$ is true, the function free() is called on each element.
 *
 * PARAMETERS
 * array            An Array object
 * deleteElements   Call the function free() on each element contained in
 *                  $array$
 * ------------------------------------------------------------------------- */
void freeArray(Array* array, bool deleteElements);

/* ------------------------------------------------------------------------- *
 * Print the content of the Array object $array$ on the standard output.
 *
 * PARAMETER
 * array            An Array object
 * ------------------------------------------------------------------------- */
void printArray(const Array* array);

#endif // !_ARRAY_H_
