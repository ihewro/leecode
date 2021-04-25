// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>

vector<int> ret;
int max_ = 0;
/**
 *
 * @param route
 * @param sum  the num of the route
 */
void backtrace(int input,vector<int> &route,int sum){
    if (sum == input){
        if (route.size() > max_){
            max_ = route.size();
            ret = route;
        }
    }
    if (sum > input){
        return ;
    }

    for (int i = 0; i <= (input-sum); ++i) {
        //去重
        if (!route.empty() && route.back() >= i){
            continue;
        }
        if (i %2 ==0){
            continue;
        }
        route.push_back(i);
        backtrace(input,route,sum+i);
        route.pop_back();
    }

}


vector<int> solution(int N) {
    vector<int> route;
    backtrace(N,route,0);
//    vector_util::print(ret);
    return ret;
}

int main(){

    solution(8);

}