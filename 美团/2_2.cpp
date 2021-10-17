//
// Created by hewro on 2021/10/17.
//

#include "bits/stdc++.h"

using namespace std;

int num = 0;

vector<vector<int>> ret;
void backtrace(int n, vector<int> &path, int level) {
    if (path.size() == n) {
        num++;
        if (num > 100){
            return ;
        }
        ret.emplace_back(path);
        return ;
    }

    for (int i = 1; i <= n; ++i) {
        if (level != i && std::find(path.begin(), path.end(), i) == path.end()) {
            path.push_back(i);
            backtrace(n,path,level+1);
            path.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> path_;
    backtrace(n,path_,1);

    std::cout << num << std::endl;

    for (const auto& path:ret) {
        for (auto item:path){
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}