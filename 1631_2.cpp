/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/29
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"
//#include "UF.hpp"
/**
 * 错误做法，直接使用动态规划是不行的，因为每走一次，都会有4种选择，但是不能成环，如果用并查集辅助，但是并查集只能连接，当递归返回的时候不能断开连接。
 */

class UF {

public:
    // 记录树的数目
    int count;
    // 节点 x 的节点是 parent[x]，存储森林的数据结构
    std::vector<int> parent;
    //存储每棵数目的节点数目，优化1，减少连接时候的树的高度
    vector<int> size;
public:

    explicit UF(int n) {
        this->count = n;
        size.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {//初始化，每个节点都是一颗树，自然每棵树的大小就是1
            parent[i] = i;
            size[i] = 1;
        }
    }

    /* 将 p 和 q 连接 */
    virtual void union_node(int p,int q){
//        std::cout << "union_node " << "p:" << p << " q:" << q <<std::endl;

        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;
        //连接两棵树
        if (size[rootQ] < size[rootP]){
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }else{
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        //树的数目减少1
        count--;
    }

    /* 判断 p 和 q 是否连通 */
    virtual bool connected(int p, int q){
        int p_parent = find(p);
        int q_parent = find(q);

        std::cout << "p:" << p << " q:"<< q << " p_parent:" << p_parent << "  q_parent:" << q_parent << std::endl;

        return p_parent == q_parent;
    }


    virtual int find(int x) {
        // 根节点的 parent[x] == x
        while (parent[x] != x){
            parent[x] = parent[parent[x]];//优化2  如这样的结构，对x=3 ,操作结果就是3放到2的父亲上面，1-2-3  --> 1-2 1-3
            x = parent[x];
        }
        return x;
    }

};
class Solution {
public:

    int row;
    int column;
    int getKey(int i, int j){
        return i * column + j;
    }

    struct tmp2 //重写仿函数
    {
        bool operator() (std::tuple<int,int,int> a,std::tuple<int,int,int> b)
        {
            if (std::get<2>(a) > std::get<2>(b)){
                return true;
            }else{
                return false;
            }
        }
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        row = heights.size();
        if (row <= 0){
            return 0;
        }
        column = heights[0].size();
        std::cout << "row:" << row << " column:" << column << std::endl;
        UF uf(row* column);
        std::priority_queue<std::tuple<int,int,int>,vector<std::tuple<int,int,int>>,tmp2> matrix{};//q(i) = (i,j,value)
        int start = 0;
        int end = getKey(row-1,column-1);
        std::cout << "end:" << end << std::endl;

        //将heights数组变成 图的数组，并进行排序，使用优先队列
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                int key_1 = getKey(i,j);
                if (j+ 1 <= column - 1){//和右边节点的边
                    int key_2 = getKey(i,j+1);
                    int value = abs(heights[i][j+1] - heights[i][j]);
                    std::tuple<int,int,int> temp  = {key_1,key_2,value};
                    matrix.push(temp);
                }
                if (i+1 <= row -1){
                    int key_2 = getKey(i+1,j);
                    int value = abs(heights[i+1][j] - heights[i][j]);
                    std::tuple<int,int,int> temp  = {key_1,key_2,value};
                    matrix.push(temp);
                }
            }
        }

        int ret = 0;
        while (!matrix.empty()) {
            auto [key_1,key_2,value] = matrix.top();
            //进行联通
            uf.union_node(key_1,key_2);
            std::cout << "union_node:" << key_1 <<"|" << key_2 << "|" << value << std::endl;
            matrix.pop();
            if (uf.connected(start,end)){
                ret = value;
                break;
            }
        }

        return ret;

    }
};

int main(){

    Solution solution;
//    vector<vector<int>> heights{{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
//    vector<vector<int>> heights{{1,2,2},{3,8,2},{5,3,5}};
    vector<vector<int>> heights {{4,3,4,10,5,5,9,2},{10,8,2,10,9,7,5,6},{5,8,10,10,10,7,4,2},{5,1,3,1,1,3,1,9},{6,4,10,6,10,9,4,6}};
    std::cout << solution.minimumEffortPath(heights) << std::endl;

}