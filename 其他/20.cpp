/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/4
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"

class Solution {
public:
    bool isValid(string s) {

        std::unordered_map<char,char> map{
                {')','('},
                {'}','{'},
                {']','['}
        };//�洢���ŵ�ƥ��



        std::unordered_set<char> left_set{
            '(','{','['
        };

        std::stack<char> char_stack;//ֻ��ջ������
        for (char & i : s) {
            if (left_set.count(i) > 0){//������
//                std::cout << "left" << std::endl;

                char_stack.push(i);
            }else{//�����ţ���pop�����Ƿ���ƥ�䵽��Ӧ��������
//                std::cout << "right" << std::endl;
                char left = map[i];
                if (char_stack.empty()){
                    return false;
                }

                auto top = char_stack.top();
                if (top == left){ //��������topջ��ƥ��
                    char_stack.pop();
//                    std::cout << "char_stack.size" << char_stack.size() << std::endl;
                }else{ //�������Ų�ƥ���������
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