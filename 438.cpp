/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/19
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret{};
        int left = 0;
        int right;

        //��p�����ֵ�����
        if (s.size() < p.size()){
            return ret;
        }
        vector<int> p_freq = getFreqOfStr(p);
        string window_str;
        window_str.assign(s,0,p.size()-1);
        vector<int> window_str_freq = getFreqOfStr(window_str);
        for (right = p.size()-1; right < s.size() ; right++) {
            //���Ҳ�ֵ���뵽������
            window_str_freq[s[right] - 'a'] ++;
            if (isSame(window_str_freq,p_freq)){
                ret.push_back(left);
            }
            //ɾ������ߵ�Ԫ��
            window_str_freq[s[left] - 'a'] --;

            left++;

        }

        return ret;
    }

    vector<int> getFreqOfStr(const string& str){
        vector<int> ret(26,0);
        for (char i : str) {
            ret[i - 'a']++;
        }
        return ret;
    }

    bool isSame(vector<int> window,vector<int> p){
        for (int i = 0; i < 26; ++i) {
            if (window[i] != p[i]){
                return false;
            }
        }
        return true;
    }
};



int main() {
    Solution solution;
    vector_util::print(solution.findAnagrams("cbaebabacd","cba"));
}