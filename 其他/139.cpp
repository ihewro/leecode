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
    string str;
    bool wordBreak(string s, vector<string>& wordDict) {
        this->str = s;
        std::unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(),-1);//0 ��ʾ �����ڣ�1 ��ʾ����
//        std::cout << "size" << s.size() << std::endl;
        bool ret =  dp_helper(0,memo,wordSet) == 1;

//        vector_util::print(memo);

        return ret;
    }

    int dp_helper(int index,vector<int> &memo,std::unordered_set<string> &wordSet){
//        std::cout << "dp_helper" << std::endl;
        if (memo[index] != -1){
//            std::cout << "dp_helper:" << index << "|" << memo[index] << std::endl;
            return memo[index];
        }


        int ret = dp(index,memo,wordSet);
        memo[index] = ret;
        return ret;

    }

    int dp(int index,vector<int> &memo,std::unordered_set<string>& wordSet){
//        std::cout << "dp: "<< index << std::endl;
        if (index == str.size() - 1){
            string s(1,str[index]);
//            std::cout << index << std::endl;
//            std::cout << s  << std::endl;
            return wordSet.count(s);
        }

        if (wordSet.count(str.substr(index,str.size() - index))){
            return 1;
        }else{
            for (int i = index; i < str.size()-1; ++i) {
                if (wordSet.count(str.substr(index,i-index+1))){
//                    std::cout <<"next" << i+1 << std::endl;
                    int ret = dp_helper(i+1, memo,wordSet);
                    if (ret == 1){
//                    std::cout << "index" << index << " i:" << i << std::endl;
                        return ret;
                    }
                }
            }
        }

        return 0;
    }
};

int main() {
    Solution solution;
    vector<string> wordDict = {"a"};
    std::cout << solution.wordBreak("a",wordDict) << std::endl;
}