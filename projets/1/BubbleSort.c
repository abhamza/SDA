/***********************************************************************
 * BubbleSort
 * Implementation of the BubbleSort algorithm.
 ***********************************************************************/

#include "Sort.h"

/* Prototypes */
void swap(const void** array, size_t firstIndex, size_t secondIndex);

/* Functions */
void swap(const void** array, size_t firstIndex, size_t secondIndex)
{
  const void* tmp = array[firstIndex];
  array[firstIndex] = array[secondIndex];
  array[secondIndex] = tmp;
}

void Sort(const void** array, size_t length, int (*comparator)(const void*, const void*))
{
  for (size_t i = 0; i < length; ++i)
    for (size_t j = i; j < length; ++j)
      if (comparator(array[i], array[j]) < 0)
        swap(array, i, j);
}

