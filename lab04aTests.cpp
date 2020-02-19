#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>

using namespace std;

int main() {

  WordCount testTable;

    // Testing makeValidWord and isWordChar
  std::string test1 = "Apple3!";
  std::string test2 = "3456A";
  std::string test3 = "O'Brien";
  std::string test4 = "-A-A-";
  std::string test5 = "Rus'";
  std::string x = WordCount::makeValidWord(test1);
  std::string y = WordCount::makeValidWord(test2);
  std::string z = WordCount::makeValidWord(test3);
  std::string a = WordCount::makeValidWord(test4);
  std::string b = WordCount::makeValidWord(test5);
  assertEquals('l', x[3], "Testing Apple3![3] = l", -1);
  assertEquals('A', y[0], "Testing 3456A[0] = A", -1);
  assertTrue((x == "Apple"), "Testing Apple3! == Apple", -1);
  assertTrue((y == "A"), "Testing 3456A == A", -1);
  assertTrue((y.length() == 1), "Length of 3456A is 1", -1);
  assertTrue((z == "O'Brien"), "O'Brien is correct", -1);
  assertTrue((a == "A-A"), "-A-A- == A-A", -1);
  assertTrue((b == "Rus"), "Rus' == Rus", -1);
  assertTrue(WordCount::isWordChar('z'), "z is a char", -1);
  assertTrue(WordCount::isWordChar('C'), "C is a char", -1);
  assertTrue(!(WordCount::isWordChar('-')), "- is not a char", -1);
  assertTrue(!(WordCount::isWordChar('1')), "1 is not a char", -1);
  assertTrue(!(WordCount::isWordChar('@')), "@ is not a char", -1);

  // Testing testTable
  assertTrue((testTable.getTotalWords() == 0), "getTotalWords = 0 when empty", -1);
  assertTrue((testTable.getNumUniqueWords() == 0), "getNumUniqueWords = 0 when empty", -1);
  testTable.incrWordCount("Hello");
  testTable.incrWordCount("Google");
  testTable.incrWordCount("Google");
  assertTrue((testTable.getNumUniqueWords() == 2), "2 unique words: Hello and Google", -1);
  assertTrue((testTable.getTotalWords() == 3), "3 total words: Hello, Google, and Google", -1);
  testTable.incrWordCount(x);
  testTable.incrWordCount(y);
  testTable.incrWordCount(z);
  testTable.incrWordCount(a);
  testTable.incrWordCount(b);
  assertTrue((testTable.getNumUniqueWords() == 7), "7 unique words, one with 2 instances", -1);
  assertTrue((testTable.getTotalWords() == 8), "8 total words, one with 2 instances", -1);
  testTable.decrWordCount(x);
  testTable.decrWordCount(y);
  testTable.decrWordCount(z);
  assertTrue((testTable.getNumUniqueWords() == 4), "Removed 3 words, now 4 unique words", -1);
  assertTrue((testTable.getTotalWords() == 5), "5 words in total after removing 3 words, 2 instances of one word", -1);
  assertTrue((testTable.getWordCount("Google") == 2), "Word Count of Google is 2", -1);
  assertTrue((testTable.getWordCount("Apple") == 0), "Word Count of Apple is 0", -1);
  
}
