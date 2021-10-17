//
// Created by hewro on 2021/10/13.
//

#include "bits/stdc++.h"

//5 5
//0 1
//3 3
//1
//2 2
using namespace std;

int end_x, end_y;
int m,n;
map<int,int> map_;
vector<vector<int>> visit;
vector<vector<int>> distances {{0,-1},{0,1},{1,0},{-1,0}};
void backtrace(int x,int y,int len){
    if (x==end_x && y==end_y){
        map_[len] ++;
    }
    for (auto pair:distances) {
        int target_x = x+pair[0];
        int target_y = y+pair[1];

        if (target_x >= m || target_y >= n || target_x < 0 || target_y < 0){
            continue;
        }

        if (!visit[target_x][target_y]){
            visit[target_x][target_y] = 1;
            backtrace(target_x,target_y,len+1);
            visit[target_x][target_y] = 0;
        }
    }
}
int main(){
    cin >> m >>n;
    int start_x, start_y; cin >> start_x >> start_y;
    cin >> end_x >> end_y;


    visit.resize(m,vector<int>(n));
    visit[start_x][start_y] = 1;

    int b;cin >>b;
    for (int i = 0; i < b; ++i) {
        int x,y;cin >> x >> y;
        visit[x][y] = 1;
    }

    backtrace(start_x,start_y,0);


    std::cout << map_.begin()->second << " " << map_.begin()->first << std::endl;

}