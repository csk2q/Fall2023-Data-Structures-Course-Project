#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <vector>

#include "Utils.h"
#include "Trie.h"

using namespace std;

int main()
{
	//for (int i = 65; i < 65 + 26; i++)
	//{
	//	char letter = i;
	//	cout << letter;
	//}
	//cout << "\n";

	//string word = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//for (int i = 0; i < word.length(); i++)
	//{
	//	int letter = word[i];
	//	cout << letter << " ";
	//}
	//cout << "\n";

	std::cout << "Hello files!\n";

#if __APPLE__ || __MACH__
	string wordsFile = "/Users/Shared/Test Files/words_alpha.txt"; //Mac
#else
	string wordsFile = "../../Data/words_alpha.txt"; //Windows
#endif

	if (!filesystem::exists(wordsFile))
	{
		cout << "File not found.\n";
		return 1;
	}

	Trie trie;

	fstream file(wordsFile);
	//vector<string> words;
	//string rawText = Utils::readAllText(file);
	string line;
	int maxWordLength = 0;
    string longestWord = "";
	while (std::getline(file, line, '\n'))
	{
		//cout << line + "\n";
		int lineLength = line.length();
		if (lineLength == 0)
			break;
		
		//words.push_back(line);
		if (!trie.addWord(line))
			cout << "Failed to add word \"" << line << "\"!\n";

		if (lineLength > maxWordLength)
        {
            maxWordLength = lineLength;
            longestWord = line;
        }
	}
    cout << longestWord << "\n";
	file.close();

	string input = " ";
	while (input.length() > 0)
	{
		cout << "Enter a word: ";

		if (cin.peek() == '\n')
			cin.ignore();
		getline(cin, input);

		bool isCorrect = trie.isValidWord(input);
		string ans = isCorrect ? "correctly!\n" : "incorrectly!\n";
		cout << "That word is spelled " << ans;
	}

	return 0;
}
