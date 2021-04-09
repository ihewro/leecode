//
// Created by hewro on 2021/4/1.
//
#include "Util.hpp"
int main(){
    vector<int> t{1,2,3};//期望结果是 1,1,2,2,3,3

    auto it = t.begin();
    while (it!=t.end()){
        it = t.insert(it+1,*it);
        it++;
    }
    vector_util::print(t);


    vector<int> tt{1,2,3};//期望结果是 1,3
    it = tt.begin();
    while (it!=tt.end()){
        if (*it == 2){
            it = tt.erase(it);
        }else{
            it++;
        }
    }
    vector_util::print(tt);
}