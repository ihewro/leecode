/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/29
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"
#include "UF.hpp"
/**
 * 错误做法，直接使用动态规划是不行的，因为每走一次，都会有4种选择，但是不能成环，如果用并查集辅助，但是并查集只能连接，当递归返回的时候不能断开连接。
 */
class Solution {
public:
    int column =0;//列数目
    int row = 0;//行数目
    vector<vector<int>> matrix;
    int minimumEffortPath(vector<vector<int>>& heights) {
        this->row = heights.size();
        if (heights.empty()){
            return 0;
        }
        this->column = heights[0].size();
//        vector<vector<int>> memo();//
        vector<vector<int>> visit(row,vector<int>(column,-1));
        matrix.resize(row,vector<int>(column,-1));
        return dp(-1,-1,0,0,heights,visit);
    }

    int getKey(int i,int j){
        return i* row + j;
    }
    //规定元素只能向右和下走
    int dp(int last_i,int last_j,int i,int j,vector<vector<int>>& heights,vector<vector<int>> & visit){
        int current_height = (last_i == -1) ? 0 : heights[last_i][last_j];

        if (last_i != -1){
            uf.union_node(getKey(last_i,last_j),getKey(i,j));
        }

        //递归终止
        if (j == row - 1 && i == column - 1){
            std::cout << "end" << std::endl;
            return abs(heights[i][j] - current_height);
        }

        int ret = INT_MAX;
        for (int k = 0; k < 4; ++k) {//普通的话是有4种方向可以选择

            int nex_i = -1,next_j=-1;

            if (k == 0 && i <= column -2){//往下走
                //判断下面的
                nex_i = i+1;
                next_j = j;
            }

            if (k == 1 && j <= row -2){//往右走
                nex_i = i;
                next_j = j + 1;
            }

            if (k == 2 &&i>=1){//往上走
                nex_i = i - 1;
                next_j = j;
            }

            if (k == 3 && j >= 1){//往左走
                nex_i = i;
                next_j = j - 1;
            }

            //判断是否可以走
            if (nex_i == -1 || next_j == -1){
                continue;
            }

            if (nex_i == last_i && next_j == last_j){
                continue;
            }

            //判断是否会成环
            if (nex_i != row -1 || next_j != column -1){
                if (uf.connected(getKey(i,j),getKey(nex_i,next_j))){
                    continue;
                }
            }

            int temp_ret = abs(heights[i][j] - current_height) + dp(i,j,nex_i,next_j,heights,uf);

            //把环断开，但是并查集没有这个函数可以断开两个节点


            if (temp_ret < ret){
                ret = temp_ret;
            }
        }

        return ret;
    }
};

int main(){

    Solution solution;
    vector<vector<int>> heights{{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    std::cout << solution.minimumEffortPath(heights) << std::endl;

}