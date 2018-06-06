#include "move.h"
#include <string>

std::string validMove(std::string s){
    std::string ans[] = {"LU", "LRU", "RU",
                         "LUD", "LURD", "RUD",
                         "LD", "LRD", "RD"};
    for(int i = 0; i < 9; ++i){
        if(s[i]=='0'){
            return ans[i];
        }
    }
    return "Not a valid State";
}

std::string applyMove(std::string s, char m){
    int z = 0;

    while(z < 9 && s[z]!='0'){
        ++z;
    }

    if(m=='U'){
        std::swap(s[z], s[z+3]);
    } else if (m=='D') {
        std::swap(s[z], s[z-3]);
    } else if (m=='L') {
        std::swap(s[z], s[z+1]);
    } else {
        std::swap(s[z], s[z-1]);
    }
    return s;
}
