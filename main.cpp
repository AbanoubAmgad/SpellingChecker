#include "Trie.h"
#include "SpellingChecker.h"
#include <iostream>
#include <windows.h>

using namespace std;
int main()
{
	SpellingChecker check;
	string dic , tst ;
	cout << "Enter The Dictionary File Name : " ;
	cin >> dic ; 
	check.loadFromFile(dic);
	cout << endl ; 
	
	cout << "Enter The File Name You Want To Check for Mis-Spelling Words : " ;
	cin >> tst ; 
	
	system ("CLS") ; 
	check.checkFile(tst);	
	
	return 0;
}

