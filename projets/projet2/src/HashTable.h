/* ========================================================================= *
 * Hash Table
 * ========================================================================= */

#ifndef _HASHTABLE_H_
# define _HASHTABLE_H_

#include <stddef.h>
#include <stdbool.h>

typedef struct HashTable_t HashTable;

HashTable* createHashTable(size_t capacity, size_t (*hashFunction)(void* key));

void freeHashTable(HashTable* hashTable);

void* insertElement(HashTable* hashTable, void* key, void* value);

void* removeElement(HashTable* hashTable, void* key);

bool hasKey(hashTable* hashTable, void* key);

#endif // !_HASHTABLE_H_
