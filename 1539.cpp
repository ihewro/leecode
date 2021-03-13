//
// Created by hewro on 2021/3/10.
//

#include "Util.hpp"

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j = 0;//指向数组的指针
        int i = 1;
        while (k > 0){
            if (i == arr[j]){
                j++;
            }else{
                k--;//找到一个缺失元素
            }
            i++;
        }
        return i-1;
    }
};



int main(){
    Solution solution;
    vector<int> input{2,3,4,7,11};
    std::cout << solution.findKthPositive(input,5) << std::endl;
}