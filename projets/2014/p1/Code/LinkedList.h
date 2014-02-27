/***********************************************************************
 * LinkedList
 * Representation of a minimalistic linked list.
 ***********************************************************************/

#ifndef _LINKED_LIST_H_
# define _LINKED_LIST_H_

typedef struct LinkedList_t LinkedList;

struct LinkedList_t
{
  int value;
  LinkedList* next;
};

#endif // !_LINKED_LIST_H_

