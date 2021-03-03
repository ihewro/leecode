/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/7
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1){
            return ;
        }
        int k = -1;
        int l = 0;
        for (int i = nums.size()-2; i >=0; i--) {
            if (nums[i] < nums[i+1]){
                k = i;
                break;
            }
        }

        if (k == -1){//k û���ҵ�
            k = -1;
            l = nums.size()-1;
        }else{
            for (int i = nums.size()-1; i >=k; i--) {
                if (nums[i] > nums[k]){
                    l = i;
                    break;
                }
            }
            //����l��kλ�õ�Ԫ��
            std::swap(nums[k],nums[l]);
        }

//        std::cout << "k:" << k << " l:" << l << std::endl;


        std::reverse(nums.begin() + k + 1,nums.end());

    }
};


int main() {
    Solution solution;
    vector<int> input{2,3,1};
    solution.nextPermutation(input);
}