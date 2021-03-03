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

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }

        std::unordered_map<char, char> key_map; //key -> value
        std::unordered_map<char, char> value_map;//value -> key

        for (int i = 0; i < s.size(); ++i) {
            if (key_map.count(s.at(i)) <= 0){
                //插入新的key的时候，需要判断value是否已经存在，如果存在，说明不符合规则
                if (value_map.count(t.at(i)) > 0){
                    return false;
                }
                key_map[s.at(i)] = t.at(i);
                value_map[t.at(i)] = s.at(i);
            }else{//如果key存在，查看映射是否匹配
                if (key_map.at(s.at(i)) != t.at(i)){
                    return false;
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