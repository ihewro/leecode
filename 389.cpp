/**
  * User: hewro
  * Date: 2020/12/17
  * Time: 16:40
  * Description:
  */
//
// Created by hewro on 2020/12/17.
//
#include <iostream>
#include <utility>
#include <vector>
#include <map>
using std::vector;


class Solution {
public:
    std::vector<char> str2vector(std::string str){
        std::vector<char> ret {};
        ret.assign(str.begin(),str.end());
        return ret;
    }
    char findTheDifference(std::string s, std::string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        int i;
        for (i = 0; i < s.size(); ++i) {
            if (t.at(i) != s.at(i)){
                return t.at(i);
            }
        }
        return t[i];
    }
};

int main(){

    Solution solution;
    std::cout << solution.findTheDifference("ae", "aea") << std::endl;
}


