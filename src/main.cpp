#include <iostream>
#include "solver.h"

int main(){
    Solver s;
    std::cin>>s.start;
    std::cout<<s.DLS(25)<<'\n';
    return 0;
}
