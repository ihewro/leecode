#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> input = {1,2,3};

vector<vector<int>> ret;
void backtrace(int index,vector<int> &path){
    if(index == input.size()){
        vector<int> temp(path.size());
        std::copy(path.begin(),path.end(),temp.begin());
        ret.push_back(temp);
        return;
    }

    for (int i = index; i < input.size(); i++){
        path.push_back(input[i]);
        backtrace(i+1, path);
        path.pop_back();
    }
}

int main() {

    vector<int> path{};
    backtrace(0,path);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            std::cout << ret[i][j] << " ";
        }
        std::cout << std::endl;
    }
//    vector_util::print2D(ret);
//    for (size_t i = 0; i < ret.size(); i++)
//    {
//        for (size_t j = 0; j < ret[j].size(); j++)
//        {
//            std::cout << ret[i][j] << " ";
//        }
//        std::cout << std::endl;
//
//    }

}