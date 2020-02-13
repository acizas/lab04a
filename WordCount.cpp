// WordCount.cpp

#include "WordCount.h"
#include <vector>

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {

  int totalWords = 0;
  // Reads through every vector in the hash table
  for (int i = 0; i < 100; i++) {
    // Checks to see if the spot in the table is occupied
    if (table[i] != NULL) {
      // Reads through every word in the vector
      //for (int j = 0; j < (table[i]).size(); j++) {
      //totalWords++;
      //}
      totalWords =+ (table[i]).size();
    }
  }
  return totalWords;
}

// Counts through every element of the table and adds the number of unique words
int WordCount::getNumUniqueWords() const {
  // If a vector in the table contains at least one word, it adds to the total
  int numUniqueWords = 0;
  for (int i = 0; i < 100; i++) {
    if (table[i] != NULL)
      numUniqueWords++;
  }
  return numUniqueWords;
    
}

int WordCount::getWordCount(std::string word) const {

  int wordCount = 0;
  // Makes the word all-lowercase and removes invalid symbols
  std::string validWord = makeValidWord(word);
  int hashKey = hash(validWord);
  // If the word is not present, returns 0 
  if (table[hashKey] == NULL) {
    return 0;
  }
  else {
    // Counts through the elements in the vector at the word's hash table index
    for (int i = 0; i < (table[hashKey]).size(); i++) {
      wordCount++;
    }
  }
  returns wordCount;
}
	
int WordCount::incrWordCount(std::string word) {

  int wordCount = 0;
  // Makes the word all-lowercase and removes invalid symbols
  std::string validWord = makeValidWord(word);
  // Checks to see if the word is in the table
  int hashKey = hash(validWord);
  if (table[hashKey] != NULL) {
    // Adds to the existing linked list and increments the word count
    (table[hashKey]).push_back(validWord);
    //for (int i = 0; i < (table[hashKey]).size(); i++){
    //wordCount++;
    //}
    wordCount = (table[hashKey]).size();
  }
  else {
    // Creates a word linked list on the table and increments the word count
    vector<word> newWord;
    table[hashKey] = newWord;
    (table[hashKey]).push_back(validWord);
    wordCount = 1;
  }
  return wordCount;
}

int WordCount::decrWordCount(std::string word) {

  int wordCount = 0;
  // Makes the word all-lowercase and removes invalid symbols
  std::string validWord = makeValidWord(word);
  int hashKey = hash(validWord);
  // Checks to see if the word is already in the table
  if (table[hashKey] != NULL) {
    // If there is more than 1 instance of the word
    if ((table[hashKey]).size() > 1) {
      (table[hashKey]).pop_back();
      // for (int i = 0; i < (table[hashKey]).size(); i++){
      //wordCount++;
      //}
      wordCount = (table[hashKey]).size();
    }
    // If there is only 1 instance of the word
    else {
      (table[hashKey]).pop_back();
      wordCount = 0;
    }
  }
  // If there is no instance of the word, returns -1
  else {
    wordCount = -1
  }
  return wordCount;
}

bool WordCount::isWordChar(char c) {

 
  // All usable letters
  char a[] = ['a','A','b','B','c','C','d','D','e','E','f','F','g','G','h','H','i','I','j','J','k','K','l','L','m','M','n','N','o','O','p','P','q','Q','r','R','s','S','t','T','u','U','v','V','w','W','x','X','y','Y','z','Z'];
   // Returns true if c is a lowercase or uppercase letter only
  for (int i = 0; i < a.size(); i++){
    if (a[i] == c)
      return true;
  }
  return false;
}

std::string WordCount::makeValidWord(std::string word) {

  string str(word);
  // Checks through every character in the string
  for (int i = 0; i < str.length(); i++) {
    // If the first or last characters are not letters, they are removed
    if (!isWordChar(str[0]))
      str.erase(0,0);
    if (!isWordChar(str[str.length()-1]))
      str.erase(str[str.length()-1], str[str.length()-1]);
    // If a character is not a letter, "-", or "'", it is removed
    if ((!isWordChar(str[i]))&&(str[i] != "-") && (str[i] != "'"))
	str.erase(i,i);
  }
  return str;
}

