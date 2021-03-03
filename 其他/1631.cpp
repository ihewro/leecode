/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/29
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"
#include "../Utils/UF.hpp"
/**
 * ����������ֱ��ʹ�ö�̬�滮�ǲ��еģ���Ϊÿ��һ�Σ�������4��ѡ�񣬵��ǲ��ܳɻ�������ò��鼯���������ǲ��鼯ֻ�����ӣ����ݹ鷵�ص�ʱ���ܶϿ����ӡ�
 */
class Solution {
public:
    int column =0;//����Ŀ
    int row = 0;//����Ŀ
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
    //�涨Ԫ��ֻ�����Һ�����
    int dp(int last_i,int last_j,int i,int j,vector<vector<int>>& heights,vector<vector<int>> & visit){
        int current_height = (last_i == -1) ? 0 : heights[last_i][last_j];

        if (last_i != -1){
            uf.union_node(getKey(last_i,last_j),getKey(i,j));
        }

        //�ݹ���ֹ
        if (j == row - 1 && i == column - 1){
            std::cout << "end" << std::endl;
            return abs(heights[i][j] - current_height);
        }

        int ret = INT_MAX;
        for (int k = 0; k < 4; ++k) {//��ͨ�Ļ�����4�ַ������ѡ��

            int nex_i = -1,next_j=-1;

            if (k == 0 && i <= column -2){//������
                //�ж������
                nex_i = i+1;
                next_j = j;
            }

            if (k == 1 && j <= row -2){//������
                nex_i = i;
                next_j = j + 1;
            }

            if (k == 2 &&i>=1){//������
                nex_i = i - 1;
                next_j = j;
            }

            if (k == 3 && j >= 1){//������
                nex_i = i;
                next_j = j - 1;
            }

            //�ж��Ƿ������
            if (nex_i == -1 || next_j == -1){
                continue;
            }

            if (nex_i == last_i && next_j == last_j){
                continue;
            }

            //�ж��Ƿ��ɻ�
            if (nex_i != row -1 || next_j != column -1){
                if (uf.connected(getKey(i,j),getKey(nex_i,next_j))){
                    continue;
                }
            }

            int temp_ret = abs(heights[i][j] - current_height) + dp(i,j,nex_i,next_j,heights,uf);

            //�ѻ��Ͽ������ǲ��鼯û������������ԶϿ������ڵ�


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