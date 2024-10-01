/*
 * File setup for thorough and exhaustive testing of hasUniqueCharacters() function from hasUniqueChars.c
 *
 * Adam Lail
 */

#include <stdio.h>    // printf
#include <stdbool.h>  // to define a boolean type and true, false
#include <string.h>   // strcpy  to copy a string
#include <assert.h>


// declaration of function from hasUniqueChars.c
bool hasUniqueChars(char * inputStr);


int main() {

  // ------------------------------------------------------------
  // Examples of declaring string constants
  /* Example 1 */
  char string1[] = "A string declared as an array.\n";

  /* Example 2 */
  char *string2 = "A string declared as a pointer.\n";

  /* Example 3 */
  char string3[128];   // can copy in up to 127 characters
                       // chose 128 because it is a multiple of 8 bytes
  strcpy(string3, "A string constant copied in.\n");

  // -------------------------------------------------------------
  // Thorough and exhaustive tests of hasUniqueChars()  
  bool ok;    // holds the result of hasUniqueChars(); used in asserts
  
  // Test 1: a test case that should return false because characters are duplicated
  strcpy(string3, "This should fail (l and s and i and h)");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  
  // Test 2: This should be true and not fail, but won't work until you
  // complete the hasUniqueChars() function
  strcpy(string3, "abcdefghij");
  ok = hasUniqueChars(string3);
  assert(ok);
  
  // Test 3: Unique characters only (1-127 ASCII)
  strcpy(string3, "abcdefghij1234567890!@#$%^&*()_+[]{}|;:',.<>?/");
  assert(hasUniqueChars(string3)); // Expected: true

  // Test 4: All printable characters (duplicates)
  strcpy(string3, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~");
  ok = hasUniqueChars(string3);
  assert(!hasUniqueChars(string3)); // Expected: false

  // Test 5: Duplicates with spaces 
  strcpy(string3, "abc abc"); 
  assert(!hasUniqueChars(string3)); // Expected: false

  // Test 6: Unique characters with spaces
  strcpy(string3, "abc def ghi");
  assert(hasUniqueChars(string3)); // Expected: true

  // Test 7: Edge case with leading and trailing spaces
  strcpy(string3, " abc ");
  assert(hasUniqueChars(string3)); // Expected: true

  // Test 8: String with multiple spaces
  strcpy(string3, "a b c");
  assert(hasUniqueChars(string3)); // Expected: true

  // Test 9: Special characters (no duplicates)
  strcpy(string3, "!@#$%^&*()-_=+[]{}|;:'\",.<>?/");
  assert(hasUniqueChars(string3)); // Expected: true

  // Test 10: Duplicates within the range of 128 characters
  strcpy(string3, "abc123!@#abc");
  assert(!hasUniqueChars(string3)); // Expected: false

  // Test 11: Empty String
  strcpy(string3, "");
  assert(hasUniqueChars(string3)); // Expected: true

  // Test 12: Valid characters with maximum allowable unique count
  strcpy(string3, "abcdefghijklmnopqrstuvwx0123456789!@#$%^&*()_+");
  assert(hasUniqueChars(string3)); // Expected: true

  // Test 13: Single character
  strcpy(string3, "Z");
  assert(hasUniqueChars(string3)); // Expected: true

  // Test 14: Non printing character
  strcpy(string3, "a b cc\n");
  ok = hasUniqueChars(string3);
  assert(ok);
  
  printf("All tests passed\n");

  return 0;
}