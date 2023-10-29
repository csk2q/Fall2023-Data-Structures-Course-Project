//Author csk2q

#ifndef GIT_GROUP_PROJECT_TRIE_H
#define GIT_GROUP_PROJECT_TRIE_H

#include "Trie.h"
#include "Node.h"

using namespace std;

class Trie
{

	//--Variables--//
private:
	const static int LETTERS_IN_ALPHABET = 26;
	Node* root[26];

	//--Methods--//

public:
	Trie();
	//    ~Trie();
	bool isValidWord(string word);

	//Returns true if successful. False if word is too long.
	bool addWord(string word);

private:



};


#endif //GIT_GROUP_PROJECT_TRIE_H
