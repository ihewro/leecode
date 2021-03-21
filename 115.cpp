//
// Created by hewro on 2021/3/17.
//

#include <bits/stdc++.h>

class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size()){
            return 0;
        }
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1));

        //初始化 dp
        for (int i = 0; i < s.size(); ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= s.size() ; ++i) {
            for (int j = 1; j <= t.size(); ++j) {
                if (s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[s.size()][t.size()];

    }
};


class Test{
public:
    void echo(){
        std::cout << "hello"  << std::endl;
    }
};

void test(void pf()){
    pf();
}
void get(){
    std::cout << "get"  << std::endl;
}
int main(){
//    Solution solution;
//    std::cout << solution.numDistinct("ra","rat") << std::endl;
//
//    const char *a = "123";
//    const char *b = "123";
//    if (a == b){
//        std::cout << " ok" << std::endl;
//    }

    Test t;
//    t.echo();
//    std::bind(&Test::echo,t);
//    std::bind(&Test::echo,t);
//    test(std::bind(&Test::echo,t));
}