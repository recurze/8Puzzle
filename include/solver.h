#ifndef SOLVER_H
#define SOLVER_H

#include <string>

class Solver{
private:
    std::string DLS(int depthLimit);
    std::string LimitedAstar(int depthLimit);
public:
    const std::string goal = "123456780";

    Solver(){};

    std::string start;

    // actual solvers
    std::string BFS();
    std::string DFS();
    std::string IDDLS();
    std::string Astar();
    std::string IDAstar();
    std::string Dijkstra();
};

#endif
