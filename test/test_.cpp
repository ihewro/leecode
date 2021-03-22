//
// Created by hewro on 2021/3/22.
//

#include <bits/stdc++.h>

using namespace std;
class UF{
private:
    int size;
public:
    map<char,char> parents;

    //p -> q
    char union_node(char p,char q){
        char root_p = find(p);
        char root_q = find(q);
        if (root_p == root_q){
            return root_p;
        }

        parents[root_q] = parents[root_p];

        return root_q;
    }


    char is_connect(char p,char q){
        char root_p = find(p);
        char root_q = find(q);
        if (root_p == root_q){
            return root_p;
        }else{
            return ' ';
        }

    }
    char find(char p){
        if(parents.count(p) <=0){
            parents[p] = p;
        }
        if (parents[p] == p){
            return p;
        }
        parents[p] = find(parents[p]);
        return parents[p];
    }
};
int main() {
    //int a;
    //cin >> a;
    UF uf;
    vector<vector<char>> input_list= {
        {'A','B','C','D','E'},
        {'F','G'},
        {'H','I','J'},
        {'A','F'}
    };

    map<char,set<char>>ret_map;

    for(auto input : input_list){
        for(int i=0;i<input.size();i++){
            uf.union_node(input[0],input[i]);
        }
    }

//    auto index_ = uf.parents.begin();
//    for(;index_ != uf.parents.end();index_++){
//        std::cout << "[ "<< index_->first <<", " << index_->second<<" ]";
//    }

    for(auto input : input_list){
        for(int i=0;i<input.size();i++){
            auto root = uf.find(input[i]);
            std::cout << root << std::endl;
            ret_map[root].insert(input[i]);
        }
    }


    auto index = ret_map.begin();
    for(;index != ret_map.end();index++){
        std::cout << "[" ;
        auto _set = index->second;
        auto beign = _set.begin();
        for(;beign != _set.end();beign++){
            std::cout << *beign << " ";
        }
        std::cout << "]" << std::endl;
    }




    return 0;
}