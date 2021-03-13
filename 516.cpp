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
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));

        for (int i = s.size()-1; i >=0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (i == j){
                    dp[i][j] = 1;
                    continue;
                }
                if (s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }else{
                    dp[i][j] = std::max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};

int main() {
    Solution solution;
    std::cout << solution.longestPalindromeSubseq("b") << std::endl;
}