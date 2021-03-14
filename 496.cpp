//
// Created by hewro on 2021/3/14.
//

#include "Util.hpp"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        std::stack<int> s;
        std::unordered_map<int, int> map;


        for (int i = 0; i < nums2.size(); ++i) {
            while (!s.empty() && nums2[i] > s.top()){
                map.insert({s.top(),nums2[i]});
                s.pop();
            }
            s.push(nums2[i]);
        }

        vector<int> ret;
        ret.reserve(nums1.size());
        for (int &i : nums1) {
            ret.push_back((map.count(i)) ? map[i] : -1);
        }

        return ret;
    }
};

int main(){
    Solution solution;
    vector<int> input1{4,1,2};
    vector<int> input2{1,3,4,2};
    vector_util::print(solution.nextGreaterElement(input1,input2));
}