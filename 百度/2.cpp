//
// Created by hewro on 2021/3/30.
//

#include "bits/stdc++.h"
using namespace std;
int main(){
    int T;scanf("%d",&T);
    for (int i = 0; i < T; ++i) {
        int n,m;scanf("%d %d",&n,&m);
        vector<vector<int>> niu(n+1);

        for (int j = 0; j < m; ++j) {
            int intervals_num;scanf("%d",&intervals_num);
            for (int k = 0; k < intervals_num; ++k) {
                int l,r;scanf("%d %d",&l,&r);
//                std::cout << "[" << l << "," << r << "]" << std::endl;
                for (int i1 = l; i1 <= r; ++i1) {
                    if (niu[i1].empty()){
                        niu[i1].emplace_back(j);
                    }else if (niu[i1].back()!=j){
                        niu[i1].emplace_back(j);
                    }else{
                        //nothing
//                        std::cout << niu[i1].back() << "nothing" << j << std::endl;
                    }
                }
            }
        }

        vector<int>ret;
//        vector_util::print2D(niu);
        for (int j = 1; j <= niu.size(); ++j) {
            if (niu[j].size()  == m){
                ret.push_back(j);
            }
        }
        std::cout << ret.size() << std::endl;
        for (int j = 0; j < ret.size(); ++j) {
            std::cout << ret[j]  << " ";
        }
        std::cout << std::endl;
    }
}