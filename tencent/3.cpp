//
// Created by hewro on 2021/3/21.
//

#include "bits/stdc++.h"
using namespace std;


int main(){
    int n;scanf("%d",&n);
    vector<vector<int>> vector_list;
    while (n > 0){
        int size;scanf("%d",&size);
        vector<int> tmp(size);
        for (int i = 0; i < size; ++i) {
            int temp;scanf("%d",&temp);
            tmp[i] = temp;
        }
        vector_list.push_back(tmp);
        n--;
    }


    int q_num;scanf("%d",&q_num);
    while (q_num > 0){
        vector<int> query_merged_list;
        int merge_list_num;scanf("%d",&merge_list_num);
        while (merge_list_num > 0){
            int list_index;scanf("%d",&list_index);
            list_index = list_index-1;
            std::copy(vector_list[list_index].begin(),vector_list[list_index].end(),back_inserter(query_merged_list));
            merge_list_num--;
        }
        int k;scanf("%d",&k);
        std::sort(query_merged_list.begin(),query_merged_list.end());
        std::cout << query_merged_list[k-1] << std::endl;
        q_num --;
    }
}