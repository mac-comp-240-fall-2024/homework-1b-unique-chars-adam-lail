/*
 * hasUniqueChars.c
 * 
 * This file provides code to check if a string contains all unique characters while making sure that only
 * printable ASCII characters are processed
 * 
 * Author: Adam Lail
 */

#include <stdio.h>  // fprintf, printf
#include <stdlib.h> // exit() defined here
#include <string.h> // useful string operations
#include <ctype.h>  //useful character operations
#include <stdbool.h>  // to define a boolean type and true, false
                      // see https://en.wikibooks.org/wiki/C_Programming/stdbool.h

#include "binary_convert.h"


/*
 * This function is for debugging by printing out the value
 * of an input insigned long as a binary string.
 */
void seeBits(unsigned long value, char *debug_text) {
  
  // string to represent binary value of variable value
  char *bin_str;

  bin_str = ulong_to_bin_str(value);
  printf("%s%s\n", debug_text, bin_str);
  free(bin_str);
  
}


/*
 * Given an input string of chars, check for any non-printing
 * characters and print an error and exit if the string has any.
 */
void checkInvalid(char * inputStr) {
  char nextChar;
  int i;
  
  for(i = 0; i < strlen(inputStr); i++) {
    nextChar = inputStr[i];

    // if nextChar is invalid (31 or less or 127 as an ascii char code), then bail out
    if ((nextChar <= 31 ) || (nextChar == 127)) {
      fprintf(stderr, "invalid character in string\n");
      exit(EXIT_FAILURE);
    }
  }
}


/*
 * TODO: Replace this code by a good description this function takes in, does and returns.
 * Include the error conditions that cause it to exit with failure.
 */
bool hasUniqueChars(char * inputStr) {

  checkInvalid(inputStr);
  
  int i;

  unsigned long checkBitsA_z = 0;   // for checking A through z and {|}~
  unsigned long checkBitsexcl_amp =0;  // for checking ! though @ 

  char nextChar;         // next character in string to check
  
  for(i = 0; i < strlen(inputStr); i++) {
    nextChar = inputStr[i];
   
    if (nextChar == ' ') {
      continue;
    }

    // Characters from 'A' to '~' (ASCII 65 to 126)
    if (nextChar >= 'A' && nextChar <= '~') {

      int bitIndex = nextChar - 'A';

      // Check if the bit is already set in checkBitsA_z
      if ((checkBitsA_z >> bitIndex) & 1) {
          return false;
      }
      checkBitsA_z |= (1UL << bitIndex); 
    }

    // Characters from '!' to '@' (ASCII 33 to 64)
    else if (nextChar >= '!' && nextChar <= '@') {
      int bitIndex = nextChar - '!';

      // Check if the bit is already set in checkBitsexcl_amp
      if ((checkBitsexcl_amp >> bitIndex) & 1) {
        return false;
      }
      checkBitsexcl_amp |= (1UL << bitIndex); 
    }

   }

  // if through all the characters, then no duplicates found
  return true;
  
}
