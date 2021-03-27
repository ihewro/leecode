//
// Created by hewro on 2021/3/27.
//
#include "bits/stdc++.h"
using namespace std;
int main(){
    int m,n;
    while (cin >> m >> n){
        bool isHave = false;
        for (int i = m; i <=n ; ++i) {
            int temp = i;
            int a = temp%10;temp=temp/10;
            int b = temp%10;temp=temp/10;
            int c = temp%10;
            int ret = pow(a,3) + pow(b,3) + pow(c,3);
            if (ret == i){
                std::cout << ret << " ";
                isHave = true;
            }
        }
        if (!isHave){
            std::cout << "no" << std::endl;
        }else{
            std::cout << std::endl;
        }
    }
}