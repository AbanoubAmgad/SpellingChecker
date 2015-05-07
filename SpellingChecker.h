#ifndef SPELLINGCHECKER_H_
#define SPELLINGCHECKER_H_

#include "Trie.h"
using namespace std;

class SpellingChecker {
private:
	Trie *dictionary;
public:
	SpellingChecker();
	void loadFromFile(string fileName);
	//loads the dictionary into a trie
	void checkFile(string fileName);
	//apply spelling checker on a given file


};
#endif 
