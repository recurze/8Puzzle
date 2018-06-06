#ifndef NODE_H
#define NODE_H

#include <string>

class Node{
public:
    int n;
    int depth;
    std::string state;
    std::string moves;

    Node(){}
    Node(std::string s, std::string m, int d){
        state = s;
        moves = m;
        depth = d;
    }
};

#endif
