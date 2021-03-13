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
    vector<int> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.resize(s.size()+1,-1);
        this->s = std::move(s);
        this->wordDict = std::move(wordDict);
        return backtrace(0);

    }

    bool backtrace(int trace_len){
        if (trace_len == s.size()){
            return true;
        }
        if (memo[trace_len] != -1){
            return memo[trace_len];
        }

        for (auto & i : wordDict) {
            if (trace_len + i.size() <=s.size()){
                if (s.substr(trace_len,i.size()) == i){
                    trace_len += i.size();
                    auto flag =  backtrace(trace_len);
                    if (!flag){
                        memo[trace_len] = 0;
                        trace_len -= i.size();
                        continue;
                    }else{
                        memo[trace_len] = 1;
                        return true;
                    }
                }else{
                    continue;
                }
            }else{
                continue;
            }

        }
        return false;
    }
};
int main() {
    Solution solution;
    vector<string> wordDict = {"leet","code"};
    std::cout << solution.wordBreak("leetcode",wordDict) << std::endl;
}