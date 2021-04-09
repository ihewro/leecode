//
// Created by hewro on 2021/4/8.
//
#include "Util.hpp"
int main(){

    vector<int> v{3,2,5,6,7,1,9};
//    std::make_heap(v.begin(),v.end());

    std::push_heap(v.begin(),v.end());

    vector_util::print(v);
}