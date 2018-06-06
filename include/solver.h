#ifndef SOLVER_H
#define SOLVER_H

#include <string>

class Solver{
public:
    const std::string goal = "123456780";

    Solver(){};

    std::string start;

    // actual solvers
    std::string BFS();
    std::string DFS();
    std::string DLS(int depthLimit);
    std::string IDS();
    std::string Astar();
    std::string Dijkstra();
};

#endif
