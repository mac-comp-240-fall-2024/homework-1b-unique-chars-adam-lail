/*
 * TODO: Add an appropriate descriptive comment here
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

  // You can uncomment these to see how the strings were initialized above.
  // Then you can comment these out again once you see that the 
  // strings were created correctly
  // printf ("%s", string1);
  // printf ("%s", string2);
  // printf ("%s", string3);

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
  
  // TODO: add your tests here

  // Test 1: Unique characters only (1-127 ASCII)
  strcpy(string3, "abcdefghij1234567890!@#$%^&*()_+[]{}|;:',.<>?/");
  assert(hasUniqueChars(string3)); // Expected: true

    // Test 2: All printable characters (should return false due to duplicates)
    strcpy(string3, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~");
     ok = hasUniqueChars(string3);
    assert(!(ok));
    // assert(!hasUniqueChars(string3)); // Expected: false

    // Test 3: Duplicates with spaces (spaces do not count)
    strcpy(string3, "abc abc"); 
    assert(!hasUniqueChars(string3)); // Expected: false

    // Test 4: Unique characters with spaces (spaces do not count)
    strcpy(string3, "abc def ghi");
    assert(hasUniqueChars(string3)); // Expected: true

    // Test 5: Edge case with leading and trailing spaces (should count as valid)
    strcpy(string3, " abc ");
    assert(hasUniqueChars(string3)); // Expected: true

    // Test 6: String with multiple spaces (should be valid)
    strcpy(string3, "a b c");
    assert(hasUniqueChars(string3)); // Expected: true

    // Test 7: Edge case with special characters (no duplicates)
    strcpy(string3, "!@#$%^&*()-_=+[]{}|;:'\",.<>?/");
    assert(hasUniqueChars(string3)); // Expected: true

    // Test 8: Duplicates within the range of 128 characters
    strcpy(string3, "abc123!@#abc");
    assert(!hasUniqueChars(string3)); // Expected: false

    // Test 9: Empty String (should return true)
    strcpy(string3, "");
    assert(hasUniqueChars(string3)); // Expected: true

    // Test 10: Valid characters with maximum allowable unique count
    strcpy(string3, "abcdefghijklmnopqrstuvwx0123456789!@#$%^&*()_+");
    assert(hasUniqueChars(string3)); // Expected: true

    // Test 11: Non-printable character included (should trigger error)
    strcpy(string3, "abc\0def"); // Contains a null character
    assert(!hasUniqueChars(string3)); // Expected: false, but will exit due to invalid character

    // Test 12: Single character (should return true)
    strcpy(string3, "Z");
    assert(hasUniqueChars(string3)); // Expected: true

    // Test 13: String with newline (should trigger invalid character error)
    strcpy(string3, "abc\n");
    assert(!hasUniqueChars(string3)); // Expected: false, will exit due to invalid character

    printf("All tests passed\n");



  // NOTE: if you add a \n to any tests, this should cause the
  //       exit failure given. Keep this test last so you can check 
  //       that others pass or fail as you expect them to.
  // strcpy(string3, "a b cc\n");
  // ok = hasUniqueChars(string3);
  // other examples that should fail that you can place in strings
  // are \0 or \t or \r
  // See problem description for more details about escape sequences
  
  return 0;
}