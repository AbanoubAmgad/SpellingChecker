#include "Trie.h"
#include "SpellingChecker.h"
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string.h>
#include <algorithm>

using namespace std;

char punctuation[] = {'.' ,',' ,'!' ,'?'};
int sizeOfArr = sizeof(punctuation)/sizeof(punctuation[0]);

SpellingChecker::SpellingChecker()
{
	dictionary = new Trie();
}

void SpellingChecker:: loadFromFile(string fileName)
{
	ifstream fin ; 
	fin.open(fileName.c_str()) ; 
	if (fin.fail())
	{
		cout<<"failed\n";
		return ;
	}
	string words ;
	while (!fin.eof()) 
	{
    	fin >> words ; 
    	dictionary->insert(words) ;
    }
    fin.close() ;
}

void SpellingChecker:: checkFile(string fileName)
{
	ifstream fin ; 
	fin.open(fileName.c_str()) ; 
	if (fin.fail())
	{
		cout<<"failed\n";
		return ;
	}
	string word;
	while (!fin.eof()) 
	{
       fin >> word ;
       //check if hte end of the word has punctuation to delete it
	   while(find(punctuation ,punctuation+sizeOfArr ,word[word.size()-1]) - (punctuation+sizeOfArr))
	   {
			word.erase(word.size()-1 ,1); //delete the punctuation char at the end of word
	   } 
       word[0] = tolower(word[0]) ; 
       if (! dictionary->doesExist(word) ) 
	   {
          cout << word << endl ;
       } 
    }
    fin.close() ;
}

