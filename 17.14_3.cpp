//
// Created by hewro on 2021/3/5.
//
#include "Util.hpp"

/**
 * 小顶堆，最小 k 个数
 */
 using namespace std;
class Solution {
public:

    void maxHeapify(vector<int>& a, int i, int heapSize) {
        std::cout << a[i] << std::endl;
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        }
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        }
    }
    vector<int> smallestK(vector<int>& arr, int k) {
        buildMaxHeap(arr,arr.size());
        return arr;
    }
};

int main(){

    Solution solution;
    vector<int> input{3,2,1,5,6,4};
    vector_util::print(solution.smallestK(input,4));

}