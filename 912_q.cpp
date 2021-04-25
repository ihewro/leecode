//
// Created by hewro on 2021/4/18.
//
#include "Util.hpp"
class Solution {
public:
    int partition(vector<int>&nums,int start,int end){
        int pivot = start;
        int i = start, j = end;
        while(i!=j){

            while(i<j){//从右往左扫描
                if(nums[j] >=  nums[pivot]){
                    j--;
                }else{
                    //此处必须是交换，而不能是 nums[pivot] = nums[j]，
                    // 这样的话 nums[pivot]的值就不是一开始 pivot位置的值了
                    std::swap(nums[pivot] ,nums[j]);
                    pivot = j;
                    break;
                }
            }
            while(i<j){//从左往右扫描
                if(nums[i] < nums[pivot]){
                    i++;
                }else{
                    std::swap(nums[pivot] ,nums[i]);
                    pivot = i;
                    break;
                }
            }
        }

        nums[i] = nums[pivot];

        return i;
    }
    void qSort(vector<int>& nums,int start,int end){
        if(start>=end){
            return ;
        }

        //rand
        int s = rand()% (end-start+1) + start;
        std::swap(nums[start],nums[s]);
        int mid = partition(nums,start,end);
        qSort(nums,start,mid-1);
        qSort(nums,mid+1,end);

    }
    vector<int> sortArray(vector<int>& nums) {
        srand(time(nullptr));
        qSort(nums,0,nums.size()-1);
        return nums;
    }
};

int main(){
    vector<int> nums{5,2,3,1};
    Solution solution;
    solution.sortArray(nums);
    vector_util::print(nums);

}