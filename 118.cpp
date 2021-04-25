//
// Created by hewro on 2021/4/21.
//

#include "Util.hpp"
class Solution {
public:
    vector<vector<int>> ret;
    void dfs(int level,int numRows){
        if (level >= numRows){
            return ;
        }

        //第一个和最后一个元素都是 1，第 level 层 有level+1 个元素
        vector<int> current(level+1,1);
        if(level > 0){
            vector<int> last = ret[level - 1];
            for(int i =1;i < current.size()-1;i++){
                std::cout << "i:" << i << " "<<last[i-1] << " " << last[i] << std::endl;
                current[i] = last[i-1] + last[i];
            }
        }
        ret.push_back(current);

        dfs(level+1,numRows);
    }
    vector<vector<int>> generate(int numRows) {
        dfs(0,numRows);
        return ret;
    }
};

int main(){
//    Solution solution;
    string s = "314567";
    int x = 0;
    int b = stoi(s, reinterpret_cast<size_t *>(&x));
    std::cout << x << std::endl;
    std::cout << b << std::endl;
//    vector_util::print2D(solution.generate(5));
}