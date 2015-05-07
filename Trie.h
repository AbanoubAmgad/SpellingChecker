#ifndef TRIE_H_
#define TRIE_H_

#include <iostream>
#include <memory.h>

using namespace std;

class Trie
{
private:
    class node
    {
    public:
        char data;                  
        bool endOfWord;                   
        int level;                  
        node *parent;               
        node* children[26];
        node()
        {
            data = ' ';
            endOfWord = false;
            level = 0;
			memset(children ,false ,sizeof(children)); //to initialize all child node by NULL
        }
        // finds if char is child of node
        node *findChild(char c){return children[c-'a'];}
    };
    
    node *root;
    
public:
    Trie()
    {
        root = new node();
    }
    // insert word into trie
    void insert(string s);
	// checks if a word exists in Trie
    bool doesExist(string s);
};

#endif 
