#include "node.h"
#include "solver.h"
#include "move.h"
#include "heuristics.h"

#include <string>
#include <unordered_set>
#include <queue>
#include <functional>

typedef std::pair<int, Node> pin;
typedef std::vector<pin> vpin;

bool c(pin a, pin b){
    return a.first > b.first;
}

std::string Solver::LimitedAstar(int depthLimit){
    std::unordered_set<Node> visited;
    std::priority_queue< pin, vpin, std::function<bool(pin, pin)> > q(c);
    std::string m, s, cs, cm;
    int cd;
    Node currNode;

    q.push({0 + h1(start), Node(start, "", 0)});
    while(!q.empty()){
        currNode = q.top().second;
        q.pop();

        cs = currNode.state;
        cm = currNode.moves;
        cd = currNode.depth;

        if(cs == goal){
            return cm;
        }

        if(cd > depthLimit){
            continue;
        }

        visited.insert(currNode);

        m = validMove(cs);
        for(int i = 0; m[i]; ++i){
            s = applyMove(cs, m[i]);
            Node temp = Node(s, cm + m[i], cd + 1);
            if(visited.find(temp) == visited.end()){
                q.push({cd + 1 + h1(s), temp});
                visited.insert(temp);
            }
        }
    }
    return "";
}

std::string Solver::IDAstar(){
    std::string s;
    int maxDepth = 40;
    for(int depth = 0; depth < maxDepth; depth += 11){
        s = LimitedAstar(depth);
        if(s != ""){
            return s;
        }
    }
    return "";
}
