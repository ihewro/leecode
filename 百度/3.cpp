//
// Created by hewro on 2021/3/30.
//
#include "bits/stdc++.h"
//n 个学生，有 m个食堂，a[i] 表示第 i 个食堂的窗口数目，每个学生等概率选择一个食堂进餐，而且选择窗口时候倾向与最长的队伍尽可能短
// 计算所有食堂内 最长队伍长度的期望

// 2 2 1 1  1.5
// 2 4 1 1 1 1 1.25
//5 5 5 5 5 5 5  1.0
using namespace std;
int main(){
    int n,m;scanf("%d %d",&n,&m);
    vector<int> a(m);
    double ret = 0;
    for (int i = 0; i < m; ++i) {
        int window_num;scanf("%d",&window_num);
        a[i] = window_num;

        //当前食堂有 a[i]个窗口，一共有 j 个学生，则最长队伍的长度为
        double temp = 0;
        for (int j = 1; j <= n; ++j) {
            int max = j / a[i] + 1;
            // n个学生都进入该食堂的概率为 1/m ^n
            //这个 j 有问题，然后这个概率不确定是不是正确的，但是思路应该是对的
            double p = pow(1.0/m , j);
            temp += p * max;
        }
        ret += std::min(temp,1.0/m);

    }

    std::cout << ret << std::endl;

    //

}