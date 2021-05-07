//
// Created by hewro on 2021/5/7.
//
#include "Util.hpp"
class Solution {
public:
    string add(string num1,string num2){
        if(num1 == ""){
            return num2;
        }
        int p1 = num1.size()-1,p2 =num2.size()-1;
        string ans;

        int add = 0;
        while(p1 >=0 || p2 >=0 || add != 0){
            int v1 = (p1 <num1.size()) ? num1[p1]-'0' : 0;
            int v2 = (p2 < num2.size()) ? num2[p2]-'0' : 0;
            p1--;p2--;
            int ret = v1 + v2 + add;
            add = ret / 10;
            ret = ret % 10;
            ans += (ret + '0');
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
    string singleMulipy(string num1,char c){
        int add = 0;
        string ans;
        for(int i = num1.size()-1;i>=0;i--){
            int ret = (num1[i] - '0') * (c - '0') + add;//记得加上 add
            add = ret / 10;
            ret = ret % 10;
            ans += (ret + '0');
        }
        if(add !=0){
            ans += (add +'0');
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        string ans = "";
        for(int i =num2.size()-1;i>=0;i--){
            string ret = singleMulipy(num1,num2[i]);
            //需要补 0
            for(int j=0;j<num2.size() -1- i;j++ ){
                ret+='0';
            }
            ans = add(ans,ret);
        }
        return ans;
    }
};

int main(){
    vector<int>s{1,2,3};
    int idx = 0;
    int end = 1;
    s[++idx] = s[end++];
    vector_util::print(s);
    std::cout << idx << " " << end;
//    Solution solution;
//    std::cout << solution.multiply("123","456");
//    std::cout << solution.singleMulipy("123",'6');
}