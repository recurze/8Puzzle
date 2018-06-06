#include "solver.h"
#include "node.h"
#include "move.h"

#include <string>
#include <stack>

std::string DLS_util(std::string cs, std::string cm, std::string goal,
                     int depthLimit){
    if (cs==goal){
        return cm;
    }
    if(depthLimit < 0){
        return "";
    }
    std::string f, m;

    m = validMove(cs);
    for(int i = 0; m[i]; ++i){
        f = DLS_util(applyMove(cs, m[i]), cm + m[i], goal, depthLimit-1);
        if(f != ""){
            return f;
        }
    }
    return "";
}

std::string Solver::DLS(int depthLimit){
    return DLS_util(start, "", goal, depthLimit);
}
