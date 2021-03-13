/**
 * Copyright (c) 2020, SeekLoud Team.
 * Author: hewro
 * Reviser: 
 * Time: 2020/12/23 12:53
 * Description: file description
 */

#include </usr/local/include/bits/stdc++.h>

using std::string;
using std::vector;
using std::set;
class Solution {
public:
    int firstUniqChar(string s) {
        vector<char> s_list(s.begin(),s.end());
        std::map<char, vector<int>> c_num{};

        for (int i = 0; i < s_list.size(); ++i) {
            if (c_num.find(s_list[i]) == c_num.end()){
                c_num[s_list[i]] = vector<int>{i};
            }else{
                c_num[s_list[i]].push_back(i);
            }
        }
        int mix = s_list.size();
        for (auto & i : c_num) {
            if (i.second.size() == 1){
                if (i.second[0] < mix){
                    mix = i.second[0];
                }
            }
        }
        if (mix == s_list.size()){
            return -1;
        }else{
            return mix;
        }
    }
};

int main(){
    string s = "loveleetcode";
    Solution solution;
//    solution.firstUniqChar(s);
    std::cout << solution.firstUniqChar(s) << std::endl;



}