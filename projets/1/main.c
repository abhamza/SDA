#include <stdlib.h>
#include <stdio.h>

#include "Event.h"
#include "Sort.h"

/* Prototypes */

/***********************************************************************
 * Compute the CPU time (in seconds) used by the Sort function.
 *
 * PARAMETERS
 * array        see Sort
 * length       see Sort
 * comparator   see Sort
 *
 * RETURN
 * seconds      The number of seconds used by Sort
 ***********************************************************************/
double cpuTimeUsedToSort(const void** array, size_t length, int (*comparator)(const void*, const void*));

/***********************************************************************
 * Compare two events using their start time.
 * This function is a comparator function as specified by the
 * Sort function.
 *
 * PARAMETERS
 * a            The first element to compare
 * b            The second element to compare
 *
 * RETURNS
 * < 0          If a starts before b
 * 0            If a and b start at same time
 * > 0          Otherwise
 ***********************************************************************/
int compareEventByStartTime(const void* a, const void* b);

/* Functions */
double cpuTimeUsedToSort(const void** array, size_t length, int (*comparator)(const void*, const void*))
{
  clock_t start = clock();
  Sort(array, length, comparator);
  return ((double)(clock() - start)) / CLOCKS_PER_SEC;
}

int compareEventByStartTime(const void* a, const void* b)
{
  return ((Event*)a)->start - ((Event*)b)->start;
}

/***********************************************************************
 * The main function.
 *
 * Generate events
 * Sort events
 * Print CPU time used to sort events
 ***********************************************************************/
int main(void)
{
  size_t numEvents = 100000;
  printf("Num. Events: %d\n", (int)numEvents);
  Event** events = createArrayOfEvents(numEvents);

  const double sec = cpuTimeUsedToSort((const void**)events, numEvents, compareEventByStartTime);
  printf("CPU Time: %f\n", sec);

  freeArrayOfEvents(events, numEvents);

  return 0;
}
