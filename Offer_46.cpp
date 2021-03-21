//
// Created by hewro on 2021/3/15.
//

#include "Util.hpp"
class Solution {
public:
    int translateNum(int num) {
        auto str = std::to_string(num);
        vector<int>dp(str.size()+1);


        dp[str.size()-1] = 1;
        dp[str.size()] = 1;
        for (int i = str.size()-1; i >= 0; --i) {
            if (str[i]!='0' && (str[i] <= '1' || (str[i] == '2' && str[i+1] <= '5'))){
                dp[i] = dp[i+1] + dp[i+2];//可以拆分两个
            }else{
                dp[i] = dp[i+1];//只能拆分一个
            }
        }
        return dp[0];

    }
};

int main(){
    Solution solution;
    std::cout << solution.translateNum(11) << std::endl;
}