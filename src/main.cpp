#include <iostream>
#include <string>
#include "solver.h"

/*
inline bool checksolvability(std::string s){
    bool ret = 1;
    for(int i = 0; i < 8; ++i){
        for(int j = i + 1; j < 9; ++j){
            ret ^= (s[i] != '0') && (s[j] != '0') && (s[i] > s[j]);
        }
    }
    return ret;
}
*/

int main(){
    Solver s;
    while(std::cin>>s.start){
        std::cout<<s.Astar()<<'\n';
        // s.Astar();
    }
    return 0;
}
