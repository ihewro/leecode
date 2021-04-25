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
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size()));
        //状态转移方程
        // dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]);
        int start=0,end=0;
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i ;j< s.size();j++){
                if(i==j){
                    dp[i][j] = true;
                    continue;
                }
                dp[i][j] = ((i+1 <= j-1) ? (dp[i+1][j-1]) : true) && s[i] == s[j];
                if(dp[i][j] && j-i > end-start){
                    start = i;
                    end = j;
                }
            }
        }

        string else_ret = "";
        else_ret.insert(1,"");
        vector<int> v;
        return s.substr(start,end-start+1);
    }
};


int main() {
//    Solution solution;
//    std::cout << solution.longestPalindrome("ac") << std::endl;

    std::cout << -50/8 << std::endl;
}