//
// Created by hewro on 2021/3/19.
//
#include "Util.hpp"
class Solution {
public:
    bool isSubsequence(string s, string t) {

        int p =0,q=0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[p] == t[q]){
                q++;
                if (q== t.size()){
                    return true;
                }
            }
            p++;
        }

        return false;
    }
};