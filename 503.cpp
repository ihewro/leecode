//
// Created by hewro on 2021/3/14.
//

#include "Util.hpp"
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        std::stack<int> stack;//存储序号
        vector<int> ret(nums.size(),-1);
        for(int i=0;i< nums.size() * 2 - 1;i++){
            int index = i % nums.size();

            if (stack.empty() || nums[index] <= nums[stack.top()]){
                stack.push(index);
            }else{
                while(!stack.empty() &&  nums[stack.top()] < nums[i]){
                    int tmp = stack.top();
                    ret[tmp] = nums[index];
                    stack.pop();
                }
                stack.push(nums[index]);
            }
        }
        return ret;

    }
};

int main(){
    Solution solution;
    vector<int> nums{1,2,1};
    vector_util::print(solution.nextGreaterElements(nums));
}