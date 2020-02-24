#include <bits/stdc++.h>

bool isPermutation(const std::string& s1, const std::string& s2){
    if (s1.size() != s2.size()){
        return false;
    }
    int characterCounts[128] = {0};
    for (char letter : s1){
        characterCounts[static_cast<size_t>(letter)] ++;
    }
    for (char letter : s2){
        characterCounts[static_cast<size_t>(letter)] --;
        if (characterCounts[static_cast<size_t>(letter)] < 0) {
            return false;
        }
    }
    return true;
};
