//
// Created by hewro on 2021/4/21.
//
#include "Util.hpp"
class Solution {
public:
    vector<string>ret;

    bool isNormalDigit(string s){
        if (s.size() == 0){
            return false;
        }
        if (s.size() == 1){
            return true;
        }
        if(stoi(s) <= 255 && s[0]!='0'){
            return true;
        }
        return false;
    }
    void backtrace(string s,int index,int dotNum,string path){
        if(dotNum == 0){
            string last_s = s.substr(index,s.size() - index);
            if(isNormalDigit(last_s)){
                path += last_s;
                ret.emplace_back(path);
            }
            return ;
        }

        for(int i = index;i<s.size();i++){
            //如果在当前 i 位置后面加一个 dot，查看后面的需要分段的数目和位数是否匹配
            //分割后看剩余的位数 要和 剩余的位数匹配
            if(s.size() - (i+1) > (dotNum-1 + 1)*3){//分段的数目是 插入的点的数目+1
                continue;
            }
            string tmp = s.substr(index,i-index+1);
            if(isNormalDigit(tmp)){
                backtrace(s,i+1,dotNum-1,path+tmp +".");
            }else{
                return ;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtrace(s,0,3,"");
        return ret;
    }
};

class Test{
public:
    int t:2;
};
int main(){

    Test test;
    test.t = 2;
    std::cout <<test.t << std::endl;

//    Solution solution;
//    vector_util::print(solution.restoreIpAddresses("25525511135"));
}