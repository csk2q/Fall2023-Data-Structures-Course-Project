//Author csk2q
#include <iostream>
#include <map>

#include "Trie.h"
#include "Utils.h"

using namespace std;

Trie::Trie()
{
	for (int i = 0; i < 26; i++)
	{
		root[i] = nullptr;
	}
}

bool Trie::isValidWord(string word)
{
	trim(word);

	if (word.length() < 1 || !isAllAlpha(word))
		return false;

	char letter = word[0];
	int letterIndex = letterToIndex(word[0]);
	Node* curNode = root[letterIndex];

	if (curNode == nullptr)
		return false;

	for (int i = 1; i < word.length(); i++)
	{
		letter = word[i];
		letterIndex = letterToIndex(word[i]);

		if (curNode->connections[letterIndex] == nullptr)
			return false;
		else
			curNode = curNode->connections[letterIndex];
	}

	return curNode->isTerminal;
}

bool Trie::addWord(string word)
{
	trim(word);

	if (word.length() < 1 || !isAllAlpha(word))
		return false;

	char letter = word[0];
	int letterIndex = letterToIndex(word[0]);

	Node* curNode;

	if (root[letterIndex] == nullptr)
		root[letterIndex] = new Node(letter, false);

	curNode = root[letterIndex];

	for (int i = 1; i < word.length(); i++)
	{
		letter = word[i];
		letterIndex = letterToIndex(word[i]);

		if (curNode->connections[letterIndex] == nullptr)
			curNode->connections[letterIndex] = new Node(letter, false);

		curNode = curNode->connections[letterIndex];
	}

	curNode->isTerminal = true;
	return true;
}

