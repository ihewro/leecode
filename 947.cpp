/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/15
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"
class UF{
public:
    int count;//联通分量的数目
    std::unordered_map<int,int> parent{};

    //key->根节点 value->树的节点数目
    std::unordered_map<int,int> size{};


    UF(){
        this->count = 0;
    }

    int find(int p){
        if (parent.count(p) <= 0){
            parent[p] = p;
            this->count ++;
        }
        while (parent[p] != p){//p不是根节点
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    void union_node(int p, int q){
        int root_p = find(p);
        int root_q = find(q);
        if (root_p == root_q){
            return ;
        }

        if (size[root_p] < size[root_q]){//节点少的树挂在节点多的树上面
            parent[root_p] = root_q;
            size[root_q] += size[root_p];
        }else{
            parent[root_q] = root_p;
            size[root_p] += size[root_q];
        }

        count --;
    }

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UF uf;
        for (auto pair: stones){
            uf.union_node(pair[0]+1,pair[1]+100001);
        }
//        std::cout << "uf.count" << uf.count << std::endl;
        return stones.size() - uf.count;
    }
};




int main(){

    Solution solution;
//    vector<vector<int>> stones = {{0,1},{1,2},{1,3},{3,3},{2,3},{0,2}};
    vector<vector<int>> stones = {{1,2},{1,3},{3,3},{3,1},{2,1},{1,0}};
    std::cout << solution.removeStones(stones) <<std::endl;
}