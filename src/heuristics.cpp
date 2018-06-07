#include "heuristics.h"

int h(std::string s){
    int ret = 0;
    for(int i = 0; s[i]; ++i){
        if(s[i]-'1' != i){
            ++ret;
        }
    }
    return ret;
}

int h1(std::string s){
    int ret = 0, n;
    for(int i = 0; s[i]; ++i){
        n = s[i]-'1';
        ret += abs(i/3 - n/3) + abs(i%3 - n%3);
    }
    return ret;
}

int h2(std::string s){
    int ret = 0, n;
    for(int i = 0; s[i]; ++i){
        n = s[i]-'1';
        ret += 2*(abs(i/3 - n/3) + abs(i%3 - n%3)) - 1;
    }
    return ret;
}
