/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/22
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */
#include "../Utils/Util.hpp"

class Solution {
public:
    std::unordered_map<char,std::vector<char>> mapping = {
            {'2',{'a', 'b', 'c'}},
            {'3',{'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9',{'w','x','y','z'}}
    };
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string track = "";
        auto it = digits.find('1');
        if (it!=std::string::npos){
            digits.erase(it,1);
        }
//        std::cout <<"digits" << digits << "  it" << it << std::endl;
        if (digits.empty()){
            return ret;
        }
        vector<char>input{};
        input.assign(digits.begin(),digits.end());
//        vector_util::print(input);
        backtrack(input, track, 0,ret);
        return ret;
    }

    void backtrack(vector<char> &digits, string &track,int track_index, vector<string> &ret){
        if (track.size() == digits.size()){
            ret.push_back(track);
            return;
        }
        auto choices = mapping[digits[track_index]];
//        vector_util::print(choices);
        for (char choice : choices) {
            track.push_back(choice);
            backtrack(digits,track,track_index+1,ret);
            track.pop_back();
        }

    }
};


int main(){
    Solution solution;

    string digits = "22";
    vector_util::print(solution.letterCombinations(digits));

}