//
// Created by hewro on 2021/9/30.
//
#include "bits/stdc++.h"

struct Point2D {
    int x;
    int y;
};

int ans = 0;
void backtrace(vector<Point2D> &nodes, vector<Point2D> &path, int index) {
    if (path.size() + (nodes.size() - index + 1) < 3){
        return ;
    }
    if (index == nodes.size()) {
        if (path.size() == 3) {
            if ((path[1].y - path[0].y) * (path[2].x - path[1].x) ==
                (path[2].y - path[1].y) * (path[1].x - path[0].x)) {
                ans ++;
            }
        }
        return ;
    }

    backtrace(nodes,path,index+1);
    path.push_back(nodes[index]);
    backtrace(nodes,path,index+1);
    path.pop_back();
}


int solution(vector<Point2D> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<Point2D> path;
    backtrace(A,path,0);
    return ans;
}

int main() {
//    vector<Point2D>  nodes{{0,1},{1,3},{3,7}};
    vector<Point2D>  nodes{{0, 0}, {1, 1}, {2, 2}, {3, 3}, {3, 2}, {4, 2}, {5, 1}};
    std::cout << solution(nodes) << std::endl;

}