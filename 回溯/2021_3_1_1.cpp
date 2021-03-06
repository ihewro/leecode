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
    vector<vector<int>>ret;//result space
    int input;
    vector<vector<int>> memo;//备忘录
    std::vector<std::vector<int>> allSum(int n){
        this->input = n;
        vector<int> route;
        backtrace(route,0);
        return ret;
    }

    /**
     *
     * @param route
     * @param sum  the num of the route
     */
    void backtrace(vector<int> &route,int sum){
        if (sum == input){
            ret.emplace_back(route);
        }

        if (sum < 0){
            return ;
        }


        for (int i = 1; i <= (input-sum); ++i) {
            //去重
            if (!route.empty() && route.back() > i){
                continue;
            }
            route.push_back(i);
            backtrace(route,sum+i);
            route.pop_back();
        }

    }

};




int main(){
    int n = 3;
    Solution solution;
    vector_util::print2D(solution.allSum(n));
}
