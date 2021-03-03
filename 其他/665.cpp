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
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() <=1){
            return true;
        }
        bool isChanged = false;
        for (int i = 0; i <= nums.size() -2; ++i) {
            if (nums[i] <= nums[i+1]){
                continue;
            }else{
                if (!isChanged){
                    //�ѵ�ǰԪ��ֵ��С����֤����num[i+1]��Ԫ�� > num[i-1]
                    //num[i-1] <= num[i+1] ���� num[i] <= num[i+2] �������޸�num[i] ֵ����ɷǵݼ�������
                    bool ret = ((i+ 2 > nums.size() -1) || (nums[i+2] >= nums[i]) ) || ((i-1 < 0) || (nums[i+1] >= nums[i-1]));
                    if (ret){
                        isChanged = true;
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
}