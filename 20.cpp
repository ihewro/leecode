/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/4
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char,char> right_c{{')','('},{']','['},{'}','{'}};
        for(int i=0;i<s.size();i++){
            if (right_c.count(s[i]) > 0){//右操作符
                if(stack.empty() || stack.top() != right_c[s[i]]){
                    return false;
                }else{
                    stack.pop();
                }
            }else{
                stack.push(s[i]);
            }
        }

        return stack.empty();
    }
};

int main() {
    Solution solution;
    std::cout << solution.isValid("]") << std::endl;
}