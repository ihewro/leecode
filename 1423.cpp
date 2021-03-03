/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/6
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if (cardPoints.empty()){
            return 0;
        }
        int left = 0;
        int right;
        int min_sum = 0;
        int temp_sum = 0;
        int all_sum = 0;
        for (right = 0; right < cardPoints.size(); ++right) {
            if (right - left < cardPoints.size() - k){//À©ÕÅ
                temp_sum += cardPoints[right];
                min_sum = temp_sum;
            }else{//»¬¶¯
                temp_sum -= cardPoints[left];
                temp_sum += cardPoints[right];

                if (temp_sum < min_sum){
                    min_sum = temp_sum;
                }
                left++;
            }

            all_sum += cardPoints[right];
        }


        return all_sum - min_sum;
    }
};

int main() {
    Solution solution;
    vector<int> points{1,2,3,4,5,6,1};
    std::cout << solution.maxScore(points,3) << std::endl;
}