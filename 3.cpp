/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/20
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        if (s.empty()) {
            return 0;
        }
        std::unordered_set<char> window{};
        int right;
        int history_max = 0;
        for (right = 0; right < s.size(); ++right) {
            if (window.count(s[right]) == 0){
                window.insert(s[right]);
//                std::cout << "insert" << s[right] << std::endl;
                history_max = std::max(history_max,(int)window.size());
            }else{
                //´°¿ÚÊÕËõ
                while (window.count(s[right]) > 0){
                    window.erase(s[left]);
//                    std::cout << "erase" << s[left] << std::endl;
                    left++;
                }
                window.insert(s[right]);
                history_max = std::max(history_max,(int)window.size());

//                std::cout << "left" << left << std::endl;
            }
        }
        return history_max;
    }
};

int main() {
    Solution solution;
    std::cout << solution.lengthOfLongestSubstring("aab") << std::endl;
}