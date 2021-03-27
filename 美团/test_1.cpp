//
// Created by hewro on 2021/3/27.
//

#include<bits/stdc++.h>

using namespace std;

int main(){
    double n;
    int m;

    while (cin >> n >> m){
        double ret=n;
        m=m-1;
        while (m >0){
            n = sqrt(n);
            ret +=n;
            m--;
        }
        cout << fixed << setprecision(2) << ret << std::endl;
    }
    return 0;


}