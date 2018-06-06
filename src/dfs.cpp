#include "node.h"
#include "solver.h"
#include "move.h"

#include <string>
#include <unordered_set>
#include <stack>

std::string Solver::DFS(){
    std::unordered_set<std::string> visited;
    std::stack<Node> q;
    std::string m, s, cs, cm;
    int cd;
    Node currNode;

    q.push(Node(start, "", 0));
    while(!q.empty()){
        currNode = q.top();
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
                q.push(Node(s, cm + m[i], cd + 1));
                visited.insert(s);
            }
        }
    }
    return "";
}
