/**
 * Copyright (c) 2020, SeekLoud Team.
 * Manager:
    * 2020/12/27: hewro
 * Develper: hewro
 * Description: 
 * Refer:
 */
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
using std::vector;
using std::string;

class Solution {
public:
    void split(const std::string& str,
               std::vector<std::string>& tokens,
               const char delim = ' ') {
        tokens.clear();
        std::istringstream iss(str);
        std::string tmp;
        while (std::getline(iss, tmp, delim)) {
            if (tmp != "") {
                // ��������ָ������ڣ��� tmp == ""�����ԡ�
                tokens.emplace_back(std::move(tmp));
            }
        }
    }

    bool wordPattern(string pattern, string s) {
        //���ݴ���
        std::vector <char> ch_list;
        ch_list.assign(pattern.begin(),pattern.end());
        std::vector<string>str_list;
        split(s,str_list,' ');

        if (str_list.size() != ch_list.size()){
            return false;
        }

        //�ж�
        std::map<char,int> key_set;
        std::map<string,int> value_set;
        for (int i = 0; i< str_list.size();i++){
            if (key_set.find(ch_list[i]) != key_set.end()){//��ǰkey�Ѿ�������
                if (value_set.find(str_list[i]) == value_set.end() || value_set[str_list[i]] != key_set[ch_list[i]]){
                    //key ���ڣ�value �����ڣ� key ���ڣ�value ���ڵ��ǲ��Ƕ�Ӧ��ӳ���ϵ
                    return false;
                }else{
                    //��ǰ��ƥ��ɹ�
                    continue;
                }
            }else{
                if (value_set.find(str_list[i]) != value_set.end()){
                    //key �����ڣ�value����
                    return false;
                }else{
                    //key�����ڣ�valueҲ���ܴ���
                    int temp = key_set.size()+1;
                    key_set[ch_list[i]] = temp;
                    value_set[str_list[i]] = temp;
                }
            }
        }
        return true;
    }
};