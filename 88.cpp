//
// Created by hewro on 2021/3/20.
//

#include "Util.hpp"
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = nums1.size()-1;
        int i = m-1, j = n-1;
        while (i>=0 && j>=0){
            if (nums1[i] > nums2[j]){
                nums1[index] = nums1[i];
                i--;
            }else{
                nums1[index] = nums2[j];
                j--;
            }
            index--;

        }
        if (j >=0){
            std::copy(nums2.begin(),nums2.begin()+j+1, nums1.begin());
        }
    }
};