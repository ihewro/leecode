/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/1
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {

        int a_sum = std::accumulate(A.begin() , A.end(),0);
        int b_sum = std::accumulate(B.begin() , B.end(),0);
        int diff = a_sum - b_sum;
        std::unordered_set<int> a_set(A.begin(),A.end());

        vector<int> ret{};
        for(auto b: B){
            int temp = diff /2  + b;
            if (a_set.count(temp) > 0){
                ret.push_back(temp);
                ret.push_back(b);
                break;
            }
        }

        return ret;

    }
};

