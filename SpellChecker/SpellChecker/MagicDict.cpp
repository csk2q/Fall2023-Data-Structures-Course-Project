#include <iostream>

#include "MagicDict.h"
#include "Utils.h"

using namespace std;

MagicDict::MagicDict(const vector<string>& words, int maxWordLength) : maxWordLength(maxWordLength)
{
	//Depth array (max word length)
	wordArray = new bool** [maxWordLength - 1];
	for (int i = 0; i < maxWordLength; i++)
	{
		//Parent array (LETTERS_IN_ALPHABET)
		wordArray[i] = new bool* [LETTERS_IN_ALPHABET];
		for (int j = 0; j < LETTERS_IN_ALPHABET; j++)
		{
			//Child array (LETTERS_IN_ALPHABET + LETTERS_IN_ALPHABET)  isValidLetter & isWordEnd
			wordArray[i][j] = new bool[LETTERS_IN_ALPHABET * 2];
			for (int k = 0; k < LETTERS_IN_ALPHABET * 2; k++)
			{
				wordArray[i][j][k] = false;
			}
		}
	}

	//Single letter array
	//singleLetterArray = new bool[LETTERS_IN_ALPHABET];
	//for (int i = 0; i < LETTERS_IN_ALPHABET; i++)
	//	singleLetterArray[0] = false;

	//Load words into array
	for (const string& word : words)
	{
		addWord(word);
	}

	//TODO output array to file or std out?
    
    ofstream myfile;
    myfile.open ("array.txt");
    for (int i = 0; i < maxWordLength - 1; ++i)
    {
        myfile << "Depth: " << i << "\n";
        myfile << "  ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
        for (int j = 0; j < LETTERS_IN_ALPHABET; ++j)
        {
            myfile << (char)(j + 65) << " ";
            for (int k = 0; k < LETTERS_IN_ALPHABET * 2; ++k)
            {
                if (wordArray[i][j][k])
                myfile << "T";
                else
                    myfile << "-";
            }
            myfile << "\n";
        }
    }
//    myfile << "Writing this to a file.\n";
    myfile.close();
}

MagicDict::~MagicDict()
{
	//TODO dealocate wordArray.
}



bool MagicDict::addWord(string word)
{
	rtrim(word);
	const int wordLength = word.length();

	if (wordLength < 1 || wordLength > maxWordLength)
		return false;

	//All single letters are valid "words"
	if (wordLength == 1)
	{
		//int index = letterToIndex(word[0]);
		//singleLetterArray[index] = true;
		return true;
	}

	for (int i = 0; i < wordLength - 1; i++)
	{
		if (isalpha(word[i]) && isalpha(word[i + 1]))
		{
			int parent = letterToIndex(word[i]);
			int child = letterToIndex(word[i + 1]);

			//Add parent-child letter link
			wordArray[i][parent][child] = true;
            
   

			//Set end of word 
			if(i == wordLength - 2)
            {
                wordArray[i][parent][child + LETTERS_IN_ALPHABET] = true;
                
                if(i == 3 && parent == 0 && child == 1)
                    cout << "break\n";
            }

		}
	}

	return true;
}

int MagicDict::letterToIndex(char letter)
{
	int offset = 65;
	int index = std::toupper(letter);
	index -= offset;

	//If letter is not a capital letter throw an error
	if (index < 0 || index > 90)
		throw invalid_argument("Non-alpha char passed to MagicDict::letterToIndex!");

	return index;
}



//--Is Valid?--//

bool MagicDict::isValidWord(string word)
{
	rtrim(word);
	const int wordLength = word.length();

	if (wordLength < 1 || wordLength > maxWordLength)
		return false;

	//All single letters are valid "words"
	if (wordLength == 1)
	{
		//int index = letterToIndex(word[0]);
		//return singleLetterArray[index];
		return true;
	}

	for (int i = 0; i < wordLength - 1; i++)
	{
		if (!isValidLetter(i, word[i], word[i + 1]))
			return false;
		if (i == wordLength - 2)
			return isWordEnd(i, word[i], word[i + 1]);
	}

	throw std::runtime_error("An unknown problem has occurred when checking if \"" + word + "\" is spelled correctly.");
}

bool MagicDict::isValidLetter(int depthOfParent, char parentLetter, char childLetter)
{
	if (!isalpha(parentLetter) || !isalpha(childLetter))
		return false;

	int parent = letterToIndex(parentLetter);
	int child = letterToIndex(childLetter);

	return wordArray[depthOfParent][parent][child];
}

bool MagicDict::isWordEnd(int depthOfParent, char parentLetter, char childLetter)
{
	if (!isalpha(parentLetter) || !isalpha(childLetter))
		return false;

	int parent = letterToIndex(parentLetter);
	int child = letterToIndex(childLetter);

	//TODO DEBUG : wordArray[3][4][30] for tree
	return wordArray[depthOfParent][parent][child + LETTERS_IN_ALPHABET];
}