/* ========================================================================= *
 * Main Function
 *
 * TODO: Implement your main function in this file.
         The following code is provided as a general guideline of the
         program to assist you in your implementation. However, you are free
         to implement it as you wish.
 * ========================================================================= */

#include "Array.h"
#include "Board.h"

int main(int argc, char** argv)
{
  // Check arguments
  if (argc != 2)
  {
    printf("Usage: %s <File>\n", argv[0]);
    return -1;
  }

  // Load the dictionary
  Array* words = createArrayFromFile(argv[1]);
  if (!words)
    return -1;

  // Human's turn

  
  // Computer's turn


  // And the winner is ...


  // Free memory


  return 0;
}
