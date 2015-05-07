#include <iostream>
#include "Trie.h"

using namespace std;

void Trie:: insert(string s)
{
    node *current = root;
    
    // if lenth of word is 0, its an empty word.
    if (s.length() == 0)
    {
        current->endOfWord = true;
        return;
    }
    
    // else insert into our trie char by char
    for (int i = 0; i < s.length(); i++)
    {
        // checks if the current char already exists as a child
        node *child = current->findChild(s[i]);
        
        // if there is already a char like ours, we dont re-insert, and we keep moving down
        if (child != NULL)
        {
            current = child;
        }
        
        // else we insert the char as the child of our node, and we keep moving down
        else
        {
            node *tmp = new node();
            tmp->data = s[i];
            current->children[s[i]-'a'] = tmp;
			tmp->parent = current;
            tmp->level = current->level + 1;
            current = tmp;
        }
        // if we are at that last char, we mark it as the end of a word
        if ( i == s.length() - 1)
        {
            current->endOfWord = true;
        }
    }
}
    
    
bool Trie:: doesExist(string s)
{
    node *current = root;
    
    while (current != NULL)
    {
        // check char by char if its child of node, then check child of child, and so on...
        for (int i = 0; i < s.length(); i++ )
        {
            node *tmp = current->findChild(s[i]);
            // if tmp = NULL then one of the chars wasn't found, therefore word does not exist.
            if (tmp == NULL)
            {
                return false;
            }
            current = tmp;
        }
        //check if current node is labeled as end of word
        if (current->endOfWord)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
