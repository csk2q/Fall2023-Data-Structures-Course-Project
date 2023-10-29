#ifndef GIT_GROUP_PROJECT_UTILS_CPP
#define GIT_GROUP_PROJECT_UTILS_CPP

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>

#include "Utils.h"

using namespace std;

//std::string Utils::readAllText(std::fstream &in)
//{
//    std::ostringstream sstr;
//    sstr << in.rdbuf();
//    return sstr.str();
//}

inline void rtrim(std::string& s)
{
	int i = s.length();
	int counter = 0;
	while (i > 0 && !isalpha(s[--i]))
		counter++;
	s = s.substr(0, s.length() - counter);
}

inline void ltrim(std::string& s)
{
    int i = 0;
    for (; i < s.length(); i++)
        if (isalpha(s[i]))
            break;

    s = s.substr(i);
}

static void trim(std::string& s)
{
    rtrim(s);
    ltrim(s);
}

int letterToIndex(char letter)
{
    int offset = 65;
    int index = std::toupper(letter);
    index -= offset;
    
    //If letter is not a capital letter throw an error
    if (index < 0 || index > 90)
        throw invalid_argument("Non-alpha char passed to MagicDict::letterToIndex!");
    
    return index;
}





#endif //GIT_GROUP_PROJECT_UTILS_CPP
