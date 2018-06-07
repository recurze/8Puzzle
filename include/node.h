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
        n = moves.length();
    }

    inline bool operator==(const Node& b) const{
        return (state == b.state && depth == b.depth);
    }

    inline bool operator<(const Node& b) const{
        return (state < b.state || depth < b.depth);
    }
};

namespace std {
    template<> struct hash<Node> {
        size_t operator()(const Node & obj) const {
            return hash<string>()(obj.state);
        }
    };
}
#endif
