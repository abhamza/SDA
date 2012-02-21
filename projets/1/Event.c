#include <stdio.h>
#include <stdlib.h>

#include "Event.h"

/* Prototypes */
Event* createEvent(void);

/* Functions */
Event* createEvent(void)
{
  Event* res = malloc(sizeof(Event));
  if (res == NULL)
    return NULL;
  res->start = time(NULL) - rand();
  res->end = res->start + rand();
  res->value = (size_t)rand();
  return res;
}

Event** createEvents(size_t numEvents)
{
  Event** res = malloc(numEvents * sizeof(Event*));
  if (res == NULL)
    return NULL;
  for (size_t i = 0; i < numEvents; ++i)
    res[i] = createEvent();
  return res;
}

void freeEvents(Event** events, size_t numEvents)
{
  if (events == NULL)
    return;
  for (size_t i = 0; i < numEvents; ++i)
    free(events[i]);
  free(events);
}

void printEvent(Event* event)
{
  if (event == NULL)
    return;
  printf("Event: %s", ctime(&event->start));
  printf("       %s", ctime(&event->end));
  printf("       %d", (int)event->value);
}

