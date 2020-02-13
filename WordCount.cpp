// WordCount.cpp

#include "WordCount.h"
#include <vector>
#include <utility>
#include <iostream>
#include <string>

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
    if (!(table[i].empty())){
      for (int j = 0; j < table[i].size(); j++) {
	if ((table[i][j]).second != 0)
	totalWords += table[i][j].second;
      }
    }
  }
  return totalWords;
}

int WordCount::getNumUniqueWords() const {
  // If a vector in the table contains at least one word, it adds to the total
  int numUniqueWords = 0;
  for (int i = 0; i < 100; i++) {
    if (!(table[i].empty())){
      for (int j = 0; j < table[i].size(); j++) {
	numUniqueWords += 1;
      }
    }
  }
  return numUniqueWords;
    
}

int WordCount::getWordCount(std::string word) const {

  int wordCount = 0;
  // Makes the word all-lowercase and removes invalid symbols
  std::string validWord = makeValidWord(word);
  int hashKey = hash(validWord);
  // If the word is not present, returns 0 
  if (table[hashKey].empty()) {
    return 0;
  }
  else {
    // Counts through the elements in the vector at the word's hash table index
    for (int i = 0; i < table[hashKey].size(); i++) {
      if (table[hashKey][i].first == validWord)
	  wordCount = table[hashKey][i].second;
    }
  }
  return wordCount;
}	
int WordCount::incrWordCount(std::string word) {

  int wordCount = 0;
  // Makes the word all-lowercase and removes invalid symbols
  std::string validWord = makeValidWord(word);
  // Checks to see if the word is in the table
  int hashKey = hash(validWord);
  if (!(table[hashKey].empty())) {
    // Adds to the existing linked list and increments the word count
    table[hashKey].second += 1;
    wordCount = table[hashKey].second;
    ;
  }
  else {
    // Creates an entry in the table for the word and returns a word count of 1
    std::vector<std::pair<word, 1>> newWord;
    table[hashKey] = newWord;
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
  for (int i = 0; i < table[hashKey].size(); i++) {
    if (table[hashKey][i].first == validWord) {
      int number = table[hashKey][i].second;
      if (number > 1) {
	table[hashKey][i].second -= 1;
	wordCount = table[hashKey][i].second;
      }
      else {
	table[hashKey][i].second -= 1;
	wordCount = 0;
      }
    }
    return wordCount;
  }
  else {
    wordCount = -1;
    return wordCount;
  }
}
    
  if (!(table[hashKey].empty())) {
    // If there is more than 1 instance of the word
    if ((table[hashKey].second) > 1) {
      table[hashKey].second - 1;
      wordCount = table[hashKey].second;
    }
    // If there is only 1 instance of the word
    else {
      table[hashKey].second - 1;
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

