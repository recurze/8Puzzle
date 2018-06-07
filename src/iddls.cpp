#include "solver.h"
#include "node.h"
#include "move.h"

#include <string>
#include <stack>
#include <unordered_set>

std::string Solver::DLS(int depthLimit){
    std::unordered_set<Node> visited;
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

        if(cd > depthLimit){
            continue;
        }

        visited.insert(currNode);

        m = validMove(cs);
        for(int i = 0; m[i]; ++i){
            s = applyMove(cs, m[i]);
            Node temp = Node(s, cm + m[i], cd + 1);
            if(visited.find(temp) == visited.end()){
                q.push(temp);
                visited.insert(temp);
            }
        }
    }
    return "";
}

std::string Solver::IDDLS(){
    std::string s;
    int maxDepth = 30;
    for(int depth = 0; depth < maxDepth; depth += 5){
        s = DLS(depth);
        if(s != "") {
            return s;
        }
    }
    return "";
}

