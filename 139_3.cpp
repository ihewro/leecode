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
    string s;
    vector<string> wordDict;
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size(),false);
        dp[0] = true;
        int j = 0;
        while (j >= s.size()){
            for (auto& word: wordDict.size()) {
                if (s.substr(i,word.size() == wordDict[j])){
                    dp[j + ,word.size()] = true;
                }
            }
        }
    }

};
int main() {
    Solution solution;
    vector<string> wordDict = {"leet","code"};
    std::cout << solution.wordBreak("leetcode",wordDict) << std::endl;
}