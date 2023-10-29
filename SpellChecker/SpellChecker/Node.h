#ifndef GIT_GROUP_PROJECT_NODE_H
#define GIT_GROUP_PROJECT_NODE_H

#include <memory>
#include <map>

using namespace std;

class Node
{
public:
    char letter = 0;
    bool isTerminal = false;
    Node* connections[26]; //26 array of node or nullptr.
    //map<char, Node> connections;
//    unique_ptr<Node> letterArray[26];
    
    Node();
    Node(char letter, bool isTerminal);
};


#endif //GIT_GROUP_PROJECT_NODE_H
