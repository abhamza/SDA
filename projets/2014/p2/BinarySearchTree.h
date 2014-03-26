/* ------------------------------------------------------------------------- *
 * BinarySearchTree
 * Interface of a binary search tree storing word/definition pairs.
 *
 * Remarks:
 * - All words are assumed to be unique.
 * - All words and all definitions must be non-NULL.
 * - A tree cannot alter the object values.
/* ------------------------------------------------------------------------- */

#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <stddef.h>
#include <stdbool.h>

// Opaque structure of a binary search tree
/* Note: You are free to define BinarySearchTree_t in any way you want. */
typedef struct BinarySearchTree_t BinarySearchTree;

/* ------------------------------------------------------------------------- *
 * Create an empty binary search tree.
 * The binary search tree must later be deleted by calling
 * freeBinarySearchTree().
 *
 * RETURN
 * tree         Pointer to an empty binary search tree
 * NULL         if an error occured
/* ------------------------------------------------------------------------- */
BinarySearchTree* createBinarySearchTree(void);

/* ------------------------------------------------------------------------- *
 * Destroy a binary search tree that has been created by
 * createBinarySearchTree(). This function does not free the content stored
 * in the tree.
 *
 * PARAMETER
 * tree         Pointer to a binary search tree
/* ------------------------------------------------------------------------- */
void freeBinarySearchTree(BinarySearchTree* tree);

/* ------------------------------------------------------------------------- *
 * Return the number of words in a binary search tree.
 *
 * PARAMETER
 * tree         Pointer to a binary search tree
 *
 * RETURN
 * size         Number of words stored in the tree
/* ------------------------------------------------------------------------- */
size_t getNumWords(BinarySearchTree* tree);

/* ------------------------------------------------------------------------- *
 * Insert a word/definition pair in a binary search tree. Both the word and
 * the definition must be different of NULL. NULL is considered as a special
 * value. If the word already exists then this function replaces the current
 * definition by the new one and returns the old one.
 *
 * PARAMETERS
 * tree         Pointer to a binary search tree
 * word         The word to insert
 * definition   The definition associated to the word
 *
 * RETURN
 * old def      Pointer to the replaced definition
 * NULL         If no definition was replaced
/* ------------------------------------------------------------------------- */
char* insertWord(BinarySearchTree* tree, char* word, char* definition);

/* ------------------------------------------------------------------------- *
 * Remove a word from a binary search tree.
 * This function returns the definition associated to the word to remove.
 *
 * PARAMETERS
 * tree         Pointer to a binary search tree
 * word         The word to remove
 *
 * RETURN
 * definition   Pointer to the definition associated to the removed word
 * NULL         If the word does not exist
/* ------------------------------------------------------------------------- */
char* removeWord(BinarySearchTree* tree, char* word);

/* ------------------------------------------------------------------------- *
 * Find a word in a binary search tree.
 *
 * PARAMETER
 * tree         Pointer to a binary search tree
 * word         The word to search
 *
 * RETURN
 * definition   The definition associated to the word
 * NULL         If the word does not exist
/* ------------------------------------------------------------------------- */
char* findWord(BinarySearchTree* tree, char* word);

/* ------------------------------------------------------------------------- *
 * Search for all words starting with a given prefix.
 * The results parameter is used as a resulting variable. This function
 * allocates memory to this variable. The user must later delete this
 * memory by calling free().
 *
 * Example of usage:
 * char* prefix = "hello";
 * char** myResults;
 * size_t numWords = findWordsByPrefix(myTree, prefix, &myResults);
 *
 * PARAMETER
 * tree         Pointer to a binary search tree
 * prefix       The prefix to look for
 * results      A valid pointer to a pointer of array of char*
 *              The pointer is set to NULL in case of allocation error
 *
 * RETURN
 * size         Number of words starting with the given prefix
/* ------------------------------------------------------------------------- */
size_t findWordsByPrefix(BinarySearchTree* tree, char* prefix, char*** results);

/* ------------------------------------------------------------------------- *
 * Check whether a binary search tree is balanced.

 * A tree is considered balanced if for all nodes in the tree
 * - both the left and right sub-trees are balanced;
 * - the difference between the heights of the left and right sub-trees
 *   is at most 1.
 *
 * PARAMETERS
 * tree         Pointer to a binary search tree
 *
 * RETURN
 * true         If the binary search is balanced
 * false        Otherwise
/* ------------------------------------------------------------------------- */
bool isBalanced(BinarySearchTree* tree);

/* ------------------------------------------------------------------------- *
 * Create a new, balanced, binary search tree from the content of the
 * given binary search tree.
 *
 * PARAMETERS
 * tree         Pointer to a binary search tree
 *
 * RETURN
 * tree         Pointer to a new, balanced, binary search tree
 * NULL         if an error occured
/* ------------------------------------------------------------------------- */
BinarySearchTree* rebalanceTree(BinarySearchTree* tree);


#endif // _BINARY_SEARCH_TREE_H_

