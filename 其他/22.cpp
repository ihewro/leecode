/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/23
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"

class Solution {
public:
    int num;
    vector<string> generateParenthesis(int n) {
        vector<string>ret{};
        string track = "";
        this->num = n;

        backtrack(track,ret,0,0);

        return ret;
    }

    void backtrack(string &track,vector<string> &ret,int left,int right){
        if (track.size() == num * 2){
            ret.push_back(track);
            return;
        }

        auto choices = returnSuitBrackets(left,right);

        for (auto brackets:choices) {
            track.push_back(brackets);
            if (brackets == '('){
                backtrack(track,ret,left+1,right);
            }else{
                backtrack(track,ret,left,right+1);
            }
            track.pop_back();
        }
    }

    vector<char> returnSuitBrackets(int left, int right){
        if (left == 0){
            return {'('};
        }
        if (left == num){
            return {')'};
        }
        if (right == num){
            return {'('};
        }

        if (right >= left){
            return {'('};
        }

        return {'(',')'};
    }
};

int main(){
    Solution solution;
    vector_util::print(solution.generateParenthesis(0));
}