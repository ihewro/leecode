/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/20
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"
class Solution {
public:

    string s;
    bool isValid(int i, int j){
        while(i < j){
            if (s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        this->s = s;
        if (s.size() == 1){
            return s;
        }
        string ret;

        int max_len = 1;
        int max_i = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i+1; j < s.size(); ++j) {
                //��ȡÿһ���Ӵ�
                if (isValid(i,j)){
                    if (j-i+1 > max_len){
                        max_i = i;
                        max_len = j-i+1;
                    }
                }

            }
        }
        return ret.assign(s,max_i,max_len);
    }
};


int main() {
    Solution solution;
    std::cout << solution.longestPalindrome("ac") << std::endl;
}