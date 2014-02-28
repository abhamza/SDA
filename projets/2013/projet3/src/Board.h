/* ========================================================================= *
 * Board
 *
 * A Board represents a 4x4 Boggle board.
 *
 * TODO: This file contains prototypes of functions that manipulate Board
         objects. You are allowed to add your own prototypes (e.g.: createBoard,
         deleteBoard, etc.) but it is striclty FORBIDDEN to change any part of
         the provided prototypes. $createBoardFromString$ will be used for
         assessment purposes.
 * ========================================================================= */

#ifndef _BOARD_H_
# define _BOARD_H_

#include "Array.h"

/* Opaque Structure */
typedef struct Board_t Board;

/* ------------------------------------------------------------------------- *
 * Create a new Board object for which the letters are initialized by $letters$
 * as follows:
 *  [0]  | [1]  | [2]  | [3]
 * ---------------------------
 *  [4]  | [5]  | [6]  | [7]
 * ---------------------------
 *  [8]  | [9]  | [10] | [11]
 * ---------------------------
 *  [12] | [13] | [14] | [15],
 * where [i] is the i-th element of $letters$.
 *
 * The Board object will later be deleted by calling freeBoard().
 *
 * PARAMETER
 * letters      A 16-character string
 *
 * RETURN
 * Board        Pointer to the new Board
 * NULL         If an error has occured. The function does not produces any
 *              error message.
 * ------------------------------------------------------------------------- */
Board* createBoardFromString(const char* letters);

/* ------------------------------------------------------------------------- *
 * Create a new Board object. The letters of the new board are randomly
 * initialized as described on https://fr.wikipedia.org/wiki/Boggle
 *
 * RETURN
 * Board        Pointer to the new Board
 * NULL         If an error has occured. The function does not produces any
 *              error message.
 * ------------------------------------------------------------------------- */
Board* createRandomBoard(void);

/* ------------------------------------------------------------------------- *
 * Free the allocated memory of the Board object $board$.
 *
 * PARAMETER
 * board        A Board object
 * ------------------------------------------------------------------------- */
void freeBoard(Board* board);

/* ------------------------------------------------------------------------- *
 * Check whether the word $word$ is present on the board $board$.
 *
 * The position of the i-th letter of $word$ on the $board$ is stored in
 * $results[i]$. The positions are defined as follows:
 *  0  | 1  | 2  | 3
 * -------------------
 *  4  | 5  | 6  | 7
 * -------------------
 *  8  | 9  | 10 | 11
 * -------------------
 *  12 | 13 | 14 | 15,
 *
 * PARAMETERS
 * board        A Board object
 * word         A null-terminated string
 *
 * RETURN-by-PARAMETER
 * results      An array of the length strlen(word)
 *
 * RETURN
 * true         If the board contains $word$
 * false        Otherwise
 * ------------------------------------------------------------------------- */
bool containsWord(Board* board, const char* word, size_t* results);

/* ------------------------------------------------------------------------- *
 * Search all valid words contained in board $board$.
 * A word is valid if it is contained in $dictionary$.
 *
 * This function exhaustively checks the validity of all paths of $board$.
 *
 * PARAMETERS
 * board        Pointer to a Board
 * dictionary   Pointer to an Array of words
 *
 * RETURN
 * array        Pointer to a new Array that contains all valid words on $board$
 * NULL         If an error has occured.
 * ------------------------------------------------------------------------- */
Array* getAllWordsByBoard(Board* board, Array* dictionary);

/* ------------------------------------------------------------------------- *
 * Search all valid words contained in board $board$.
 * A word is valid if it is contained in $dictionary$.
 *
 * This function checks the presence of all words from $dictionary$ on $board$.
 *
 * PARAMETERS
 * board        Pointer to a Board
 * dictionary   Pointer to an Array of words
 *
 * RETURN
 * array        Pointer to a new Array that contains all valid words on $board$
 * NULL         If an error has occured.
 * ------------------------------------------------------------------------- */
Array* getAllWordsByDictionary(Board* board, Array* dictionary);

/* ------------------------------------------------------------------------- *
 * Search all valid words contained in board $board$.
 * A word is valid if it is contained in $dictionary$.
 *
 * This function checks the presence of all words from $dictionary$ on $board$.
 * In order to speed up the procedure, the function uses a dynamic programming
 * approach.
 *
 * PARAMETERS
 * board        Pointer to a Board
 * dictionary   Pointer to an Array of words
 *
 * RETURN
 * array        Pointer to a new Array that contains all valid words on $board$
 * NULL         If an error has occured.
 * ------------------------------------------------------------------------- */
Array* getAllWordsByDynamicProgramming(Board* board, Array* dictionary);

#endif // !_BOARD_H_
