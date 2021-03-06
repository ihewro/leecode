//
// Created by hewro on 2021/3/5.
//
#include "Util.hpp"

/**
 * 快速选择算法，最小 k 个数
 */
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        helper(arr,0,arr.size()-1,k);
        return vector<int>(arr.begin(),arr.begin()+k);

    }

    void helper(vector<int>& arr,int start,int end, int k){
        if (start >=end){
            return;
        }
        int p = partition(arr,start,end);
        if (p > k){
            helper(arr,start,p-1,k);
        }else if (p <k){
            helper(arr,p+1,end,k);
        }else{
            return ;
        }

    }

    int partition(vector<int> &arr, int start, int end) {
        int pivot = arr[start];
        int i = start;
        int j = end;
        //找到 pivot 的位置
        while (i != j) {

            //此时 i 指向 pivot
            while (i < j && arr[j] > pivot) {
                j--;
            }
            arr[i] = arr[j];
            //此时 j 是指向 pivot，虽然 j 位置没有赋值为 pivot
            while (i < j && arr[i] <= pivot) {
                i++;
            }
            //找到左侧但是第一个大于 pivot 的值
            arr[j] = arr[i];
        }

        //最后才把pivot 位置进行赋值
        arr[i] = pivot;

        return i;
    }

};

int main(){

    Solution solution;
    vector<int> input{1,3,5,7,2,4,6,8};
    vector_util::print(solution.smallestK(input,4));

}