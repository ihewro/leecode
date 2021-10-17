//
// Created by hewro on 2021/10/17.
//
#include "bits/stdc++.h"
//输入描述
//        第一行一个数T表示数据组数。
//
//对每组数据，第一行两个空格隔开的数n和m表示有n个节点m条边。
//
//接下来一行有m个”[ui, vi ]”（ui≠vi，1≤ui,vi≤n）形式的输入，第i个表示第i条双向边连接了ui与vi号节点。输入格式见样例。
//
//* 输入格式说明：每个边数据不包含引号，u和v之间以英文逗号和一个空格隔开；每两个边数据中间以空格隔开，行末无空格
//
//        输出描述
//输出T行，每行一个Yes或者No，当给定的图是树的时候输出Yes，否则输出No
//
//
//        样例输入
//2
//3 2
//[1, 2] [1, 3]
//4 3
//[1, 2] [2, 3] [1, 3]

using namespace std;

class UF {
    int n_;
    vector<int> parent;
    vector<int> size;
public:
    UF(int n):n_(n){
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n_; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    void connect(int p,int q){
        int root_p = find(p);
        int root_q = find(q);
        if (root_p == root_q){
            return ;
        }

        if (size[root_p] < size[root_q]){
            parent[root_p] = root_q;
            size[root_q] += size[root_p];
        }else{
            parent[root_q] = root_p;
            size[root_p] += size[root_q];
        }
    }

    bool is_connect(int p, int q){
        return find(p) == find(q);
    }
    int find(int p ){
        while(parent[p] != p){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return parent[p];
    }

};

int main() {
    char a1,a2,a3,a4;
    int x,y;
    cin >>a1 >> x ;

//    cin >>a1 >> x >> a2 >> a3 >> y >>a4;
    std::cout <<a1 <<x << a2  << a3 <<  y  <<a4;
    return 0;
    int T;//数据组数
    cin >> T;
    while (T > 0){
        T --;
        int n,m;cin >> n >> m;// 节点、边数
        UF uf(n);
        bool is_tree = true;
        getchar();
        for (int i = 0; i < m; ++i) {
            char a1,a2,a3;
            int x,y;
//            cin >> a1,
            scanf("[%d, %d]",&x,&y);
            if (uf.is_connect(x,y)){
                is_tree = false;
                std::cout << "No" << std::endl;
                break;
            }else{
                uf.connect(x,y);
            }
        }
        if (is_tree){
            std::cout << "Yes" << std::endl;
        }
    }
}