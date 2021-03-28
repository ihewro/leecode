//
// Created by hewro on 2021/3/28.
//

#include "bits/stdc++.h"
class Solution {
public:
    int numDifferentIntegers(string word) {
        std::unordered_set<string> set;
        int left =0,right=0;
        string temp;
        while (right < word.size()){
            auto r = word[right];
            right++;
            if (r>=48 && r<=57){//数字
                if (temp.empty()){
                    temp += r;
                }else {
                    if (temp.front() == '0'){
                        temp.pop_back();
                    }
                    temp += r;
                }
            }else{//遇到了字母，则将之前窗口收缩
                if (!temp.empty()){
                    set.insert(temp);
                }
                temp = "";
            }
        }
        if (!temp.empty()){
            set.insert(temp);
        }

        return set.size();
    }
};

int main(){
//    char t = 0x00000001;
//    std::cout << t << std::endl;
//    std::cout << (int)'9' << std::endl;
    Solution solution;
    std::cout << solution.numDifferentIntegers("8510") << std::endl;
}