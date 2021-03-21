//
// Created by hewro on 2021/3/20.
//

#include "Util.hpp"
void bubbleSort(vector<int> &nums){
    for (int i = 0; i < nums.size(); ++i) {
        //冒泡
        for (int j = 0; j < nums.size() - i - 1; ++j) {
            if (nums[j] >nums[j+1] ){
                //交换
                std::swap(nums[j], nums[j+1]);
            }
        }
    }
}

int main(){

    vector<int> input{3,2,1,4,4,4,5,7};
    bubbleSort(input);
    vector_util::print(input);

}