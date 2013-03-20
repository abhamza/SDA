/* ========================================================================= *
 * Array
 * ========================================================================= */

#ifndef _ARRAY_H_
# define _ARRAY_H_

#include <stddef.h>

typedef struct Array_t {
    void* values;
    size_t length;
} Array;

#endif // !_ARRAY_H_
