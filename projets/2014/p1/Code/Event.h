/***********************************************************************
 * Event
 * Representation of an event with start date, end date and a value.
 ***********************************************************************/
#ifndef _EVENT_H_
# define _EVENT_H_

# include <stddef.h>
# include <time.h>
# include "LinkedList.h"

/* Types */
typedef struct Event_t Event;

struct Event_t
{
  time_t start;
  time_t end;
  size_t value;
};

/***********************************************************************
 * Create an array of random Event objects.
 * The array must later be deleted by calling freeArrayOfEvents().
 *
 * PARAMETER
 * numEvents  Size of the array
 *
 * RETURN
 * array      A new array of Event
 ***********************************************************************/
Event** createArrayOfEvents(size_t numEvents);

/***********************************************************************
 * Destroy an array of Event that has been created by createArrayOfEvents().
 * This function also deletes the Event objects in the array.
 *
 * PARAMETERS
 * events     An array of Event
 * numEvents  Length of the array
 ***********************************************************************/
void freeArrayOfEvents(Event** events, size_t numEvents);

/***********************************************************************
 * Create a linked list of random Event objects.
 * The linked list must later be deleted by calling freeLinkedListOfEvents().
 *
 * PARAMETER
 * numEvents  Number of events
 *
 * RETURN
 * list       Pointer to the first element of the linked list of Event.
 ***********************************************************************/
LinkedList* createLinkedListOfEvents(size_t numEvents);


/***********************************************************************
 * Destroy an linked list of Event that has been created by
 * createLinkedListOfEvents().
 * This function also deletes the Event objects in the list.
 *
 * PARAMETERS
 * events     An array of Event
 * numEvents  Length of the array
 ***********************************************************************/
void freeLinkedListOfEvents(LinkedList* list);

/***********************************************************************
 * Print an Event on the standard output.
 *
 * PARAMETER
 * event      Pointer to an Event
 ***********************************************************************/
void printEvent(Event* event);

#endif // !_EVENT_H_

