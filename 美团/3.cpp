//
// Created by hewro on 2021/3/27.
//

/**
 * 统计
 * @return
 */
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;int m;
    scanf("%d %d",&n,&m);//改进了
    unordered_map<int,vector<int>>map{};
    for (int i = 1; i <= n; ++i) {
        int item;scanf("%d",&item);
        if (map.count(item) <= 0){
            map[item]= {i,i};//改进了，不要用 push_back
        }else{
            map[item][1] = i;
        }
    }

    for (int i = 0; i < m; ++i) {
        int item;scanf("%d",&item);
        if (map.count(item) > 0){
            printf("%d %d\n",map[item][0],map[item][1]);
        }else{
            std::cout << 0 << std::endl;
        }

    }


}