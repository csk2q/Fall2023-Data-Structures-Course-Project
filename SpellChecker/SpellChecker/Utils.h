#ifndef GIT_GROUP_PROJECT_UTILS_H
#define GIT_GROUP_PROJECT_UTILS_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>

using namespace std;

    //std::string readAllText(std::fstream& in);

    //Removes white space from the back of a string
    inline void rtrim(std::string& s);
    inline void ltrim(std::string& s);
    static void trim(std::string& s);
    static int letterToIndex(char letter);
    static string toLower(const string& word);

#include "Utils.cpp"
#endif //GIT_GROUP_PROJECT_UTILS_H
