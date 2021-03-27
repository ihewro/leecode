//
// Created by hewro on 2021/3/27.
//

#include "Util.hpp"
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        std::reverse(s.begin(),s.end());
        std::reverse(s.begin(),s.begin()+s.size()-n);
        std::reverse(s.begin()+s.size()-n,s.end());

        return s;
    }
};