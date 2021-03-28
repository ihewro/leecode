//
// Created by hewro on 2021/3/28.
//
#include "bits/stdc++.h"

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int left=0,right=0;
        std::unordered_map<string,string>map;
        for(auto pair:knowledge){
            map[pair[0]] = pair[1];
        }

        string ret;
        bool isLeft = false;
        while (right < s.size()){
            auto r = s[right];
            right++;

            if (r == '('){
                isLeft = true;
                left = right - 1;
            }else if (r == ')'){
                string str = s.substr(left+1,right - left - 2);
//                std::cout << str << std::endl;
                if (map.count(str) > 0){
                    ret += map[str];
                }else{
                    ret += '?';
                }
                left = right;
                isLeft = false;
            }else{
                if (!isLeft){
                    ret += r;
                }
            }
        }

        return ret;
    }
};
int main(){
    Solution solution;
    vector<vector<string>> input{
        {"name","bob"},{"age","two"}
    };
    std::cout << solution.evaluate("(name)is(age)yearsold",input);
}