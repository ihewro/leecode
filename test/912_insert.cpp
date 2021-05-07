//
// Created by hewro on 2021/5/6.
//

#include "Util.hpp"
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty() || matrix[0].empty()){
            return ans;
        }
        int row = matrix.size();
        int column = matrix[0].size-1;
        int top=0,right=column-1,bottom=row-1,left=0;
        int len = row * column;
        while(len > 0){
            for(int i=top;i<=right;i++){
                ans.push_back(nums[top][i]);
                len--;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans.push_back(nums[i][right]);
                len--;
            }
            right--;
            for(int i=right;i>=left;i--){
                ans.push_back(nums[bottom][i]);
                len--;
            }
            bottom--;
            for(int i =bottom;i>=top;i--){
                ans.push_back(nums[i][left]);
                len--;
            }
            left++;
        }
    }
    return ans;
};

int main(){
    Solution solution;
    vector<int> nums{5,2,3,1};
    solution.sortArray(nums);

}