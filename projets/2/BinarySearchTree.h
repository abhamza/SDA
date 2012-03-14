/***********************************************************************
 * BinarySearchTree
 * Interface of a binary search tree.
 *
 * Remarks:
 * - All keys are assumed to be unique.
 * - All keys are associated to non-NULL objects.
 * - A tree cannot alter the object values.
 ***********************************************************************/

#ifndef _BINARY_SEARCH_TREE_H_
# define _BINARY_SEARCH_TREE_H_

# include <stddef.h>

// Opaque structure of a binary search tree
/* Note: You are free to define BinarySearchTree_t in any way you want. */
typedef struct BinarySearchTree_t BinarySearchTree;

/***********************************************************************
 * Create an empty binary search tree.
 * The binary search tree must later be deleted by calling
 * freeBinarySearchTree().
 *
 * RETURN
 * tree         Pointer to an empty binary search tree
 * NULL         if an error occured
 ***********************************************************************/
BinarySearchTree* createEmptyBinarySearchTree(void);

/***********************************************************************
 * Create a balanced binary search tree from keys/values arrays.
 * The object associated to the keys[i] is values[i], for 0 <= i < numElements.
 * Each keys[i] is unique and each values[i] is != NULL.
 * The binary search tree must later be deleted by calling
 * freeBinarySearchTree().
 *
 * PARAMETERS
 * keys         An array of unique keys to insert in the tree
 * values       An array of objects associated to the array of keys
 * numElements  Size of both arrays keys and values
 *
 * RETURN
 * tree         Pointer to a binary search tree
 * NULL         if an error occured
 ***********************************************************************/
BinarySearchTree* createBinarySearchTree(int* keys, const void** values, size_t numElements);

/***********************************************************************
 * Destroy a binary search tree that has been created by
 * createEmptyBinarySearchTree() or createBinarySearchTree().
 * This function do not delete the objects stored in the tree.
 *
 * PARAMETER
 * tree         Pointer to a binary search tree
 ***********************************************************************/
void freeBinarySearchTree(BinarySearchTree* tree);

/***********************************************************************
 * Return the number of elements in a binary search tree.
 *
 * PARAMETER
 * tree         Pointer to a binary search tree
 *
 * RETURN
 * size         Number of elements stored in the tree
 ***********************************************************************/
size_t getNumElements(const BinarySearchTree* tree);

/***********************************************************************
 * Insert a key/value element in a binary search tree. The value must be
 * different of NULL. NULL is considered as a special value.
 * If the key already exists then this function replaces the current
 * object by the new one and returns the old one.
 *
 * PARAMETERS
 * tree         Pointer to a binary search tree
 * key          The key to insert
 * value        The object associated to the key
 *
 * RETURN
 * old value    Pointer to the replaced object
 * NULL         If no object was replaced
 ***********************************************************************/
const void* insertElement(BinarySearchTree* tree, int key, const void* value);

/***********************************************************************
 * Remove an element from a binary search tree.
 * This function returns the object associated to the key to remove.
 *
 * PARAMETERS
 * tree         Pointer to a binary search tree
 * key          The key to remove
 *
 * RETURN
 * object       Pointer to the object associated to the removed key
 * NULL         If the key does not exist
 ***********************************************************************/
const void* removeElement(BinarySearchTree* tree, int key);

/***********************************************************************
 * Find an element in a binary search tree.
 *
 * PARAMETER
 * tree         Pointer to a binary search tree
 * key          The key to search
 *
 * RETURN
 * object       The value associated to the key
 * NULL         If the key does not exist
 ***********************************************************************/
const void* findElement(const BinarySearchTree* tree, int key);

/***********************************************************************
 * Return the rank of a key in a binary search tree.
 * The rank of a key is its position in the sorted list (in ascending order)
 * of all keys contained in the tree. The key with the lowest value has a
 * rank of 0 and the key with the highest value has a rank of
 * getNumElements()-1.
 *
 * PARAMETER
 * tree         Pointer to a binary search tree
 * key          The key
 *
 * RETURN
 * >= 0         The rank of the key
 * < 0          If the key does not exist
 ***********************************************************************/
int getRankOf(const BinarySearchTree* tree, size_t key);

/***********************************************************************
 * Search for all objects whose keys are within the range [keyMin; keyMax].
 * The results parameter is used as a resulting variable. This function
 * allocates memory to this variable. The user must later deletes this
 * memory by calling free().
 *
 * Example of usage:
 * const void** myResults;
 * size_t numElements = getElementsInRange(myTree, x, y, &myResults);
 *
 * PARAMETER
 * tree         Pointer to a binary search tree
 * keyMin       Lower bound of the range
 * keyMax       Upper bound of the range
 * results      A valid pointer to a pointer of array of const void*
 *              The pointer is set to NULL in case of allocation error
 *
 * RETURN
 * size         Number of elements in range [keyMin; keyMax]
 ***********************************************************************/
size_t getElementsInRange(const BinarySearchTree* tree, size_t keyMin, size_t keyMax, const void*** results);

#endif // _BINARY_SEARCH_TREE_H_

