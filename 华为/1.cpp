//
// Created by hewro on 2021/10/13.
//

#include "bits/stdc++.h"

using namespace std;
int main(){

    int a,b,n; std::cin >>a >> b >> n ;


    int max_room_id = 0;

    vector<std::pair<int,int>> list;
    for (int i = 0; i < n; ++i) {
        int x,y;
        std::cin >> x >> y;
        list.emplace_back(x,y);
        max_room_id = std::max(std::max(x,y),max_room_id);
    }
    n = max_room_id;

    vector<vector<int>> edge(n+1, vector<int>(n+1,0));
    vector<int> dist(n+1,INT_MAX);
    dist[a] = 1;


    for(auto item : list){
        int x = item.first, y = item.second;
        edge[x][y] = 1;
        edge[y][x] = 1;
        if (x == a){
            dist[y] = 1;
        }
    }


    std::unordered_set<int> t;

    for (int i = 1; i <=n ; ++i) {
        if (i!=a){
            t.insert(i);
        }
    }

    while(!t.empty()){
        int min = INT_MAX;
        int min_index = -1;
        for (auto i: t) {
            if (dist[i] < min){
                min_index = i;
                min = dist[i];
            }
        }
        if (min_index == -1){
            break;
        }
        t.erase(min_index);

        for (int i = 1; i <= n ; ++i) {
            if (i != a && i!=min_index && edge[min_index][i]){
                dist[i] = std::min(dist[i],dist[min_index] + 1);
            }
        }
    }

    std::cout << dist[b] << std::endl;

}