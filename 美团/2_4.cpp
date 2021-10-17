//
// Created by hewro on 2021/10/17.
//
#include "bits/stdc++.h"

using namespace std;
int main(){
    int T;cin >> T;
    while(T >0){
        T --;
        int a ,m ,y; cin >> a >> m>> y;
        int x = 0;
        int tmp  = 1;
        unordered_set<int> set_;
        int zero_tmp = tmp % m;
        if (zero_tmp == y){
            return 0;
        }
        set_.insert(zero_tmp);

        while (true){
            x ++;
            tmp = a * tmp;
            int else_tmp = tmp % m;
            if (set_.count(else_tmp)){
                std::cout << -1 << std::endl;
                break;
            }
            set_.insert(else_tmp);
            if (else_tmp == y){
                std::cout <<  x << std::endl;
                break;
            }
        }
    }

}