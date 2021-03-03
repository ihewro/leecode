/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/2
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"

class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.empty()){
            return 0;
        }
        int left = 0;
        int right;
        int history_max = 1;//�������ڳ�ʼ��СΪ1
        std::unordered_map<char,int> map{};//��¼���������е���ĸ�ظ�����
        map[s[0]] = 1;
        for (right= 1; right < s.size(); ++right) {
            //���´����е���ĸ�ظ�����
            if (map.count(s[right]) > 0){
                map[s[right]]++;
            }else{
                map[s[right]] = 1;
            }
            history_max = std::max(history_max,map[s[right]]);//����max
            if (history_max + k > right - left ){//���ţ�right - left = ֮ǰ�Ļ������ڴ�С
                //rightÿ��++ �����left���仯������������
            }else{//����
                map[s[left]] --;
                left ++;
            }
        }

        return right - left;

    }
};

int main() {
    Solution solution;
}