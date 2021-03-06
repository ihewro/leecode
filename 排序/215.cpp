//
// Created by hewro on 2021/3/6.
//

#include "Util.hpp"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        helper(nums,0,nums.size()-1,k);
        return nums[k];
    }

    void  helper(vector<int>& nums,int start,int end,int k){
        if (start >= end){
            return ;
        }
        int p = partition(nums,start,end);
        std::cout << "p:" << p << std::endl;
        if (p == k){
            return ;
        }else if (p>k){
            return helper(nums,start,p-1,k);
        }else{
            return helper(nums,p+1,end,k);
        }
    }

    int partition(vector<int>& nums,int start,int end){
        int i = start;int j = end;
        int pivot = nums[i];
        while (i!=j){
            //i 指向 pivot
            while(i<j && nums[j] > pivot){
                j--;
            }
            nums[i] = nums[j];

            //j 指向 pivot
            while (i<j && nums[i] <= pivot){
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        return i;
    }
};

int main(){
    Solution solution;
    vector<int> input{2,1,3,4,5,6};
    std::cout << solution.findKthLargest(input,6);

}