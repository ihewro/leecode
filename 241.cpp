/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/23
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:
    string _input;
    vector<int> diffWaysToCompute(string input) {
        if (input.empty()){
            return vector<int>();
        }
        this->_input = input;
        return computeAllPossibility(0,_input.size()-1);
    }

    vector<int> computeAllPossibility(int i, int j){

        vector<int> ret{};
        for (int k = i; k <= j; ++k) {
            if (_input[k] == '+' || _input[k] == '-' || _input[k] == '*'){

                auto left = computeAllPossibility(i,k-1);
                auto right = computeAllPossibility(k+1,j);

                for (auto left_:left){
                    for (auto right_:right){
                        ret.push_back(calculate(_input[k],left_,right_));
                    }
                }
            }

        }

        //base case
        if (ret.empty()){
            ret.push_back(std::stoi(_input.substr(i,j-i+1)));
        }

        return ret;
    }

    int calculate(char op,int a,int b){
        switch (op) {
            case '+':
                return a+b;

            case '-':
                return a-b;
            case '*':
                return a*b;
        }
        return 0;
    }
};


int main() {
    Solution solution;
    vector_util::print(solution.diffWaysToCompute("2*3-4*5"));
}