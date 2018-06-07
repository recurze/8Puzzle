#include <iostream>
#include "solver.h"

int main(){
    Solver s;
    std::cin>>s.start;
    std::cout<<s.Astar()<<'\n';
    return 0;
}
