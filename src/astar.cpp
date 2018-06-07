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

bool compare(pin a, pin b){
    return a.first > b.first;
}

std::string Solver::Astar(){
    std::unordered_set<std::string> visited;
    std::priority_queue< pin, vpin, std::function<bool(pin, pin)> > q(compare);
    //std::priority_queue< pin > q;
    std::string m, s, cs, cm;
    int cd;
    Node currNode;

    q.push({0 + h1(start), Node(start, "", 0)});
    // q.push({0 + h(start), Node(start, "", 0)});
    while(!q.empty()){
        currNode = q.top().second;
        q.pop();

        cs = currNode.state;
        cm = currNode.moves;
        cd = currNode.depth;

        if(cs == goal){
            return cm;
        }

        visited.insert(cs);

        m = validMove(cs);
        for(int i = 0; m[i]; ++i){
            s = applyMove(cs, m[i]);
            if(visited.find(s) == visited.end()){
                q.push({cd + 1 + h1(s), Node(s, cm + m[i], cd + 1)});
                // q.push({cd + 1 + h(s), Node(s, cm + m[i], cd + 1)});
                visited.insert(s);
            }
        }
    }
    return "";
}
