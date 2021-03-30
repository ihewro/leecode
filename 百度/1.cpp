//
// Created by hewro on 2021/3/30.
//

#include "bits/stdc++.h"
using namespace std;
int main(){
    int T;scanf("%d",&T);
    for (int i = 0; i < T; ++i) {
        int n,m;scanf("%d %d",&n,&m);
        vector<int> expect_num(n);
        vector<int> have_num(m);
        vector<int>ret(n,0);

//        map<int,int>map()
        for (int j = 0; j < n; ++j) {
            int want; scanf("%d",&want);
            expect_num[j] = want;
        }
        for (int j = 0; j < m; ++j) {
            int have;scanf("%d",&have);
            have_num[j] = have;
        }

        std::sort(have_num.begin(),have_num.end());
//        vector_util::print(have_num);


        for (int j = 0; j < n; ++j) {
            auto pos = have_num.end() - std::lower_bound(have_num.begin(),have_num.end(),expect_num[j]);
            std::cout << pos <<  " ";
        }
        std::cout << std::endl;
    }
}