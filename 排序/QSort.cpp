//
// Created by hewro on 2021/3/5.
//


#include "Util.hpp"

class Solution {

private:
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

    void qSort(vector<int> &input, int start, int end) {
        if (start >= end) {
            return;
        }
        int p = partition(input, start, end);
        qSort(input, start, p - 1);
        qSort(input, p + 1, end);
    }

public:
    vector<int> sortArray(vector<int> &nums) {
        qSort(nums, 0, nums.size() - 1);
        return nums;
    }

};

int main() {

    vector<int> input{2, 1, 3, 4, 6, 5};
    Solution solution;
    vector_util::print(input);
}