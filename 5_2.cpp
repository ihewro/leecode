/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/20
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"
class Solution {
public:

    string longestPalindrome(string s) {
        if (s.size() < 1){
            return s;
        }

        //��ʼ��dp����
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),true));
        int max_len = 1;
        int max_start = 0;

        for (int i = s.size()-2; i >=0 ; --i) {
            for (int j = i+1; j < s.size(); ++j) {
                dp[i][j] = dp[i+1][j-1] && s[i] == s[j];

                if (dp[i][j] && j-i+1 > max_len){
                    max_len = j-i+1;
                    max_start = i;
                }
            }
        }

        return s.substr(max_start,max_len);
    }
};


int main() {
    Solution solution;
    std::cout << solution.longestPalindrome("cbbd") << std::endl;
}