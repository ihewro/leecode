//
// Created by hewro on 2021/3/20.
//
#include "Util.hpp"
void selectSort(vector<int> &nums){
    for (int i = 0; i < nums.size(); ++i) {
        int min_index = 0;
        for (int j = 1; j < nums.size() - i; ++j) {
            if (nums[j] > nums[min_index]){
                min_index = j;
            }
        }
        std::swap(nums[min_index],nums[nums.size() - i - 1]);
    }
}

int main(){

    vector<int> input{3,2,1,4,4,4,5,7};
    selectSort(input);
    vector_util::print(input);

}