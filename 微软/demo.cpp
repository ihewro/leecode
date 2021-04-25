//
// Created by hewro on 2021/4/11.
//

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::set<int> set;
    int max= INT_MIN;
    for(int i = 0;i< A.size();i++){
        if(A[i] > max){
            max = A[i];
        }
        set.insert(A[i]);
    }

    auto it = set.begin();
    while (it!=set.end()){
        std::cout << *it << " ";
        it++;
    }

    std::cout <<  std::endl;

    std::cout << max  << std::endl;
    if (max <=0 ){
        return 1;
    }
    for(int i=1;i<max;i++){
        std::cout << set.count(i) << std::endl;
        if(set.count(i)<=0){
            return i;
        }
    }

    return max+1;    // write your code in C++14 (g++ 6.2.0)
    std::set<int> set;
    int max= INT_MIN;
    for(int i = 0;i< A.size();i++){
        if(A[i] > max){
            max = A[i];
        }
        set.insert(A[i]);
    }

    auto it = set.begin();
    while (it!=set.end()){
        std::cout << *it << " ";
        it++;
    }

    std::cout <<  std::endl;

    std::cout << max  << std::endl;
    if (max <=0 ){
        return 1;
    }
    for(int i=1;i<max;i++){
        std::cout << set.count(i) << std::endl;
        if(set.count(i)<=0){
            return i;
        }
    }

    return max+1;

}


int main(){
    vector<int> nums{1,2,3};
    std::cout << solution(nums) << std::endl;
}