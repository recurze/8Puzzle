#include <iostream>
#include "solver.h"

int main(){
    Solver s;
    std::cin>>s.start;
    std::cout<<s.DFS()<<'\n';
    return 0;
}
