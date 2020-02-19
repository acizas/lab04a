#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>

using namespace std;

int main() {

  WordCount testTable;

    // Testing makeValidWord and isWordChar
  std::string test1 = "Apple3!";
  std::string test2 = "3456A";
  std::string x = makeValidWord(test1);
  std::string y = makeValidWord(test2);
  assertEquals('l', test1[3], "Testing Apple3![3] = l", -1);
  assertEquals('A', test2[0], "Testing 3456A[0] = A", -1);
  assertTrue((x == "Apple"), "Testing Apple3! == Apple", -1);
  assertTrue((y == "A"), "Testing 3456A == A", -1);
  assertTrue((y.length() == 1), "Length of 3456A is 1", -1);

  assertTrue(isWordChar('z'), "z is a char", -1);
  assertTrue(isWordChar('C'), "C is a char", -1);
  assertTrue(!(isWordChar('-'), "- is not a char", -1);
  assertTrue(!(isWordChar('1'), "1 is not a char", -1);
  assertTrue(!(isWordChar('@'), "@ is not a char", -1);
}
