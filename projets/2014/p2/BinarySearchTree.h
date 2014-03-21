/* ------------------------------------------------------------------------- *
 * BinarySearchTree
 * Interface of a binary search tree storing word/definition pairs.
 *
 * Remarks:
 * - All keys are assumed to be unique.
 * - All keys are associated to non-NULL objects.
 * - A tree cannot alter the object values.
/* ------------------------------------------------------------------------- */

#ifndef _BINARY_SEARCH_TREE_H_
# define _BINARY_SEARCH_TREE_H_

# include <stddef.h>

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
 * createBinarySearchTree(). This function do not free the content stored
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
size_t getNumWords(const BinarySearchTree* tree);

/* ------------------------------------------------------------------------- *
 * Insert a word/definition pair in a binary search tree. The definition
 * must be different of NULL. NULL is considered as a special value.
 * If the word already exists then this function replaces the current
 * definition by the new one and returns the old one.
 *
 * PARAMETERS
 * tree         Pointer to a binary search tree
 * word         The word to insert
 * definition   The definition associated to the key
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
 * definition   The definition associated to the key
 * NULL         If the word does not exist
/* ------------------------------------------------------------------------- */
char* findWord(const BinarySearchTree* tree, char* word);


// findWordsByPrefix
// isBalanced
// rebalanceTree

#endif // _BINARY_SEARCH_TREE_H_

