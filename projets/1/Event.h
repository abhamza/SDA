#ifndef _EVENT_H_
# define _EVENT_H_

# include <stddef.h>
# include <time.h>

/* Types */
struct Event_t
{
  time_t start;
  time_t end;
  size_t value;
};

typedef struct Event_t Event;

/***********************************************************************
 * Create an array of random Event.
 * The returned array must later be deleted by calling freeEvents()
 *
 * PARAMETER
 * numEvents  Size of the array
 *
 * RETURN
 * array      A new array of Event
 ***********************************************************************/
Event** createEvents(size_t numEvents);

/***********************************************************************
 * Destroy an array of Event that has been created by createEvents().
 * This function also deletes Event in the array.
 *
 * PARAMETERS
 * events     An array of Event
 * numEvents  Length of the array
 ***********************************************************************/
void freeEvents(Event** events, size_t numEvents);

/***********************************************************************
 * Print an Event on the standard output.
 *
 * PARAMETER
 * event      Pointer to an Event
 ***********************************************************************/
void printEvent(Event* event);

#endif // !_EVENT_H_

