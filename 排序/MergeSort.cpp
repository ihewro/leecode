//
// Created by hewro on 2021/3/20.
//
#include "Util.hpp"

extern int a;

class Solution {
    vector<int> tmp;//辅助数组
    void merge(vector<int> &nums,int a_i,int a_j, int b_i, int b_j){
        int left = a_i, right= b_i;
        int index = a_i;
        while (left <= a_j && right <= b_j){
            if (nums[left] < nums[right]){
                tmp[index] = nums[left];
                left++;
            }else{
                tmp[index] = nums[right];
                right++;
            }

            index++;
        }
        if (left<= a_j){
            std::copy(nums.begin() + left,nums.begin()+a_j+1,tmp.begin()+index);
        }
        if (right <=b_j){
            std::copy(nums.begin() + right,nums.begin()+b_j+1,tmp.begin()+index);
        }
        std::copy(tmp.begin()+a_i,tmp.begin()+b_j+1,nums.begin()+a_i);

    }
    void  mergeSortRecursive(vector<int> &nums,int start,int end){
        //base case
        if (start>=end){
            return;
        }

        int mid = (start + end) / 2;
        mergeSortRecursive(nums,start,mid);
        mergeSortRecursive(nums,mid+1,end);

        merge(nums,start,mid,mid+1,end);

    }
public:

    void sortArray(vector<int> &nums){
        tmp.resize(nums.size());
        mergeSortRecursive(nums,0,nums.size()-1);
    }


};

int main(){
    Solution solution;
    vector<int> input{3,2,1,4,4,4,5,7};
    solution.sortArray(input);
    vector_util::print(input);
}

