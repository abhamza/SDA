/* ========================================================================= *
 * Implementation of Board.h
 * ========================================================================= */

#include "Board.h"

#include <stdlib.h>

Board* createRandomBoard(void)
{
  static const size_t numDice = 16;
  static const size_t numFaces = 6;

  static const char* const dice[] = {
    "etukno", "evgtin", "decamp", "ielruw",
    "ehifse", "recals", "entdos", "ofxria",
    "navedz", "eioata", "glenyu", "bmaqjo",
    "tlibra", "spulte", "aimsor", "enhris"
  };

  // Generate string from dice
  char result[numDice + 1];
  result[numDice] = '\0';
  for (size_t i = 0; i < numDice; ++i)
  {
    const int side = rand() % numFaces;
    result[i] = dice[i][side];
  }

  // randomize position of letters
  for (size_t i = 0; i < numDice; ++i)
  {
    const int newIndex = rand() % numDice;
    char swapedLetter = result[i];
    result[i] = result[newIndex];
    result[newIndex] = swapedLetter;
  }

  return createBoardFromString(result);
}
