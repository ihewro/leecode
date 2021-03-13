/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/21
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty() || text2.empty()){
            return 0;
        }
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),0));
        for (int i = 0; i < text1.size(); ++i) {
            for (int j = 0; j < text2.size(); ++j) {
                if (i== 0 && j == 0){
                    if (text1[i] == text2[j]){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = 0;
                    }
                    continue;
                }
                if (text1[i] == text2[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }


        return dp[text1.size()-1][text2.size()-1];

    }
};


int main() {
    Solution solution;
    std::cout << solution.longestCommonSubsequence("abcde","ace");
}