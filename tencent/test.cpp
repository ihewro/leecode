////
//// Created by hewro on 2021/4/30.
////
#include "Util.hpp"
//class Solution {
//public:
//    int row = 0;
//    int cloumn = 0;
//    int ret = 0;
//    vector<vector<int>> visit;
//    int longestIncreasingPath(vector<vector<int>>& matrix) {
//        if (matrix.empty()){
//            return 0;
//        }
//        row = matrix.size();//行数
//        cloumn = matrix[0].size();//列数
//        visit.resize(row,vector<int>(cloumn,0));//记录是否遍历过
//        //对每个节点进行遍历
//
//        for(int i=0;i<row;i++){
//            for(int j =0;j<cloumn;j++){
//                // if(!visit[i][j]){
//                // dfs(matrix,i,j,0,-1);
//                // }
//                if(i == 1 && j == 3){
//                    cout << "ok" <<
//                }
//                dfs(matrix,i,j,0,-1);
//            }
//        }
//        return ret;
//
//    }
//    bool isOk(int i,int j){
//        if(i < 0 || j < 0){
//            return false;
//        }
//        if(i >= row || j>= cloumn){
//            return false;
//        }
//        return true;
//
//    }
//    //返回路径长度
//    void dfs(vector<vector<int>>& matrix,int i,int j,int len,int lastValue){
//        //base case
//        if(!isOk(i,j)){
//            ret = std::max(ret,len);
//            return ;
//        }
//        vector<vector<int>> directons = {{-1,0},{1,0},{0,1},{0,-1}};
//        for(int index = 0;index<directons.size();index++){
//            int new_i = directons[index][0] + i;
//            int new_j = directons[index][1] + j;
//            bool flag = isOk(new_i,new_j);
//            int choice = 0;
//
//            if(flag){
//                choice = matrix[new_i][new_j];
//                if(matrix[new_i][new_j] <= matrix[i][j]){//不是递增的
//                    continue;
//                }
//                // if( visit[new_i][new_j] == 1) {//已经访问过了
//                //     continue;
//                // }
//                // visit[new_i][new_j] = 1;
//            }
//
//            dfs(matrix,new_i,new_j,len+1,choice);
//
//            if(flag){
//                // visit[new_i][new_j] = 0;
//            }
//        }
//    }
//};


class Solution {
public:
    int row;//行数
    int column;//列数
    int ans = 0;
    vector<vector<int>> visit;
    bool isOk(int i,int j){
        if(i<0 || j < 0 || i>= row || j >= column){
            return false;
        }else{
            return true;
        }
    }
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    //len 是指 path的路径长度
    void backtrace(vector<vector<int>>& matrix,int len,int i,int j){
        //base case
        if (!isOk(i,j)){
            return ;
        }
        len ++;//选中当前 i,j 的节点
        ans = std::max(ans,len);

        for(auto pair : directions){
            int new_i = i + pair[0];
            int new_j = j + pair[1];

            if(isOk(new_i,new_j) && matrix[new_i][new_j] > matrix[i][j]){//不是递增的则剪枝
                backtrace(matrix,len,new_i,new_j);
            }
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        row = matrix.size();
        column = matrix[0].size();
        // visit.resize(row,vector<int>(column,0));
        for(int i = 0;i<row;i++){
            for(int j = 0;j<column;j++){
                backtrace(matrix,0,i,j);
            }
        }
        return ans;

    }
};


class A {
public:
    virtual void PrintA()  {
        std::cout << "A";
    }
    virtual void PrintA2()  {
        std::cout << "A2";
    }
//	virtual void PrintA()  {
//		cout << "A";
//	}
};

class B {
public:
    virtual void PrintB()  {
        std::cout << "B";
    }
    virtual void PrintB2()  {
        std::cout << "B2";
    }
//	virtual void PrintB()  {
//		cout << "B";
//	}
};



int main(){
    A* pa = new A();
    B* pb = (B*)pa;
    pb->PrintB2();
}
//
//int main(){
//    Solution solution;
//    vector<vector<int>> input{{9,9,4},{6,6,8},{2,1,1}};
//    std::cout << solution.longestIncreasingPath(input);
//}

