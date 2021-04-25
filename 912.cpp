//
// Created by hewro on 2021/4/15.
//
#include <unistd.h>
#include "Util.hpp"
class Solution {
public:
    vector<int> tmp;
    void merge(vector<int>& nums,int start, int mid ,int end){
        int i=start,j=mid+1,index = start;
        while(i<=mid || j<=end){//每次选择小的数字放入 tmp 中
            int i_v = (i<=mid) ? nums[i] : INT_MAX;
            int j_v = (j<=end) ? nums[j] : INT_MAX;
            if(i_v < j_v){
//                std::cout << index << ":" << i_v << " |" << i << "mid" << mid << " ";
                i++;
;
                tmp[index] = i_v;
            }else{
                j++;
//                std::cout << index << ":" << j_v << " ||" << j << " ";

                tmp[index] = j_v;
            }
            index++;
        }

        std::cout << start << ":" << end << ":" << mid << std::endl;
        vector_util::print(tmp);
        std::copy(tmp.begin()+start,tmp.begin() + start + (end - start + 1),nums.begin()+start);
        vector_util::print(nums);

    }

    void mergeSort(vector<int>& nums,int start,int end){
        if(start >= end){
            return ;
        }
        int mid = (start + end) / 2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,start,mid,end);

    }
    //归并排序
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize(nums.size(),0);
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};


int main() {
    for (int i = 0; i < 2; i ++){
        fork();
        printf("wowo ");
//        std::cout << "ok" << std::endl;
    }
}