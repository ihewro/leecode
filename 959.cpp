/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/26
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class UF{
public:
    int count;
    vector<int> parent;
    vector<int> size;
    UF(int n){
        this->count = n;
        //初始化
        parent.resize(count);
        size.resize(count);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }


    void union_node(int p,int q){
        int root_p = find(p);
        int root_q = find(q);
        if (root_p == root_q){
            return ;
        }
        if (size[root_p] < size[root_q]){
            parent[root_p] = root_q;
            size[root_q] += size[root_p];
        }else{
            parent[root_q] = root_p;
            size[root_p] += size[root_q];
        }

        this->count --;
    }

    int find(int p){
        while (parent[p] != p){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }


};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        UF uf(grid.size() * grid.size() * 4);

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                int begin_index_0 = (i * grid.size() + j) * 4;
                int begin_index_1 = begin_index_0 + 1;
                int begin_index_2 = begin_index_1 + 1;
                int begin_index_3 = begin_index_2+ 1;
                //每个单元格内部节点连接
                if (grid[i][j] == ' '){//空格
                    uf.union_node(begin_index_0,begin_index_1);
                    uf.union_node(begin_index_2,begin_index_3);
                    uf.union_node(begin_index_1,begin_index_2);
                }
                if (grid[i][j] == '/'){
                    uf.union_node(begin_index_0,begin_index_1);
                    uf.union_node(begin_index_2,begin_index_3);
                }
                if (grid[i][j] == '\\'){
                    uf.union_node(begin_index_0,begin_index_3);
                    uf.union_node(begin_index_1,begin_index_2);
                }

                //单元格之间连接
                //和下面一行的单元格一个节点连接
                if (i + 1 < grid.size()){
                    int next_begin_index_1 = ((i+1) * grid.size() + j) * 4 + 1;
                    uf.union_node(begin_index_3,next_begin_index_1);
                }
                //和右边一列的单元格的一个节点连接
                if (j + 1 < grid.size()){
                    int next_begin_index_0 = (i * grid.size() + j + 1) * 4;
                    uf.union_node(begin_index_2,next_begin_index_0);
                }


            }
        }
        return uf.count;

    }
};


int main(){

}