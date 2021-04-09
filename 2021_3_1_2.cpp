//
// Created by hewro on 2021/3/3.
//

#include "Util.hpp"

/*
 * 整数拆分
 * 从命令行读取一个整数，分解为多个整数之和，并打印所有不同序列，每行一个，比如3：
 * 1+1+1
 * 2+1
 * 3
 */


class Solution{
public:
    std::vector<std::vector<int>> allSum(int n){

        vector<vector<vector<int>>> dp(n+1);
        dp[0] = {{}};
        dp[1] = {{1}};

        vector<vector<int>> ret = {{1}};
        for (int i = 2; i <= n; ++i) {
            for (int j = i; j >=1 ; --j) {
                int k = i-j;
                //dp[k] 和 j 合并
                for (int l = 0; l < dp[k].size(); ++l) {
                    if (!dp[k][l].empty() && dp[k][l].back() <= j){
                        vector<int>temp = {j};
                        std::copy(dp[k][l].begin(),dp[k][l].end(),std::back_inserter(temp));
                        dp[i].push_back(temp);
                    }

                }
            }
        }
        return dp[n];
    }
};




int main(){
    int n = 7;
    Solution solution;
    vector_util::print2D(solution.allSum(n));

//    vector<int> d_1{1,2,5};
//    vector<int> d_2{4,6,7};
//    vector<int>d_3;
//    std::copy(d_1.begin(),d_1.end(),std::back_inserter(d_2));
////    std::merge(d_1.begin(),d_1.end(),d_2.begin(),d_2.end(),std::back_inserter(d_3));
//
//    vector_util::print(d_2);
}
