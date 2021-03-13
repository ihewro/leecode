/**
 * Copyright (c) 2020, SeekLoud Team.
 * Manager:
    * 2020/12/27: hewro
 * Develper: hewro
 * Description: 
 * Refer:
 */


#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
using std::vector;
using std::string;
#include "Util.hpp"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        std::unordered_map<char,char> s2t_map;
        std::unordered_set<char> t_set;
        for (int i = 0; i < s.size(); ++i) {
            if (s2t_map.count(s[i]) <=0){
                if (t_set.count(t[i]) <=0){
                    s2t_map[s[i]] = t[i];
                    t_set.insert(t[i]);
                }else{
                    return false;
                }
            }else{
                if (s2t_map[s[i]] != t[i]){
                    return false;
                }else{
                    continue;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    string s = "egg";
    string t = "asd";
    std::cout << solution.isIsomorphic(s,t) << std::endl;
}