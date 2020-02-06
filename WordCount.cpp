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
      for (int j = 0; j < (table[i]).size(); j++) {

	totalWords++;
	
      }
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

  // Makes the word all-lowercase and removes invalid symbols
  std::string validWord = makeValidWord(word);

  

  
}

int WordCount::decrWordCount(std::string word) {
	// STUB
	return -2;
}

bool WordCount::isWordChar(char c) {
	// STUB
	return false;
}

std::string WordCount::makeValidWord(std::string word) {
	// STUB
	return "";
}
