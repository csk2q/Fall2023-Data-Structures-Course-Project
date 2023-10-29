#include <iostream>

#include "Node.h"

Node::Node() : Node(0, false)
{
	cout << "Invalid node created?\n";
}

Node::Node(char letter, bool isTerminal = false) : letter(letter), isTerminal(isTerminal)
{
	for (int i = 0; i < 26; i++)
	{
		connections[i] = nullptr;
	}
}
