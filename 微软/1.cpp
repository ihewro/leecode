// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include "bits/stdc++.h"

//D={3,2,4} T = {"MPM","","G"}

int solution(vector<int> &D, vector<string> &T) {
    // write your code in C++14 (g++ 6.2.0)

    std::unordered_map<char,int> map{
            {'P', 0},
            {'G',1},
            {'M',2}
    };
    vector<int>time_list(3,0);//P G M
    vector<int>max_truck(3,0);//P G M

    for (int i= 0;i<T.size();i++) {
        for (int j = 0; j < T[i].size(); ++j) {
            auto t = T[i][j];

            time_list[map[t]] +=1;
            max_truck[map[t]] = i;
        }
    }

//    vector_util::print(max_truck);

    for (int i = 0; i < max_truck.size(); ++i) {
        for (int j = 0; j <= max_truck[i]; ++j) {
            time_list[i] +=D[j]*2;
        }
    }
    return *std::max_element(time_list.begin(),time_list.end());
}

int main(){
    vector<int> D{2,5};
    vector<string>T{"PGP","M"};
    std::cout << solution(D,T) << std::endl;
}
