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

        std::unordered_map<char,char> map{
                {')','('},
                {'}','{'},
                {']','['}
        };//´æ´¢À¨ºÅµÄÆ¥Åä



        std::unordered_set<char> left_set{
            '(','{','['
        };

        std::stack<char> char_stack;//Ö»ÈëÕ»×óÀ¨ºÅ
        for (char & i : s) {
            if (left_set.count(i) > 0){//×óÀ¨ºÅ
//                std::cout << "left" << std::endl;

                char_stack.push(i);
            }else{//ÓÒÀ¨ºÅ£¬¾Ípop£¬¿´ÊÇ·ñÄÜÆ¥Åäµ½ÏàÓ¦µÄ×îÀ¨ºÅ
//                std::cout << "right" << std::endl;
                char left = map[i];
                if (char_stack.empty()){
                    return false;
                }

                auto top = char_stack.top();
                if (top == left){ //×óÀ¨ºÅÓëtopÕ»¶¥Æ¥Åä
                    char_stack.pop();
//                    std::cout << "char_stack.size" << char_stack.size() << std::endl;
                }else{ //ÓëÓÒÀ¨ºÅ²»Æ¥ÅäµÄ×óÀ¨ºÅ
                    return false;
                }
            }
        }

//        std::cout << char_stack.size() << std::endl;

        return char_stack.empty();


    }
};


int main() {
    Solution solution;
    std::cout << solution.isValid("{[]}") << std::endl;
}