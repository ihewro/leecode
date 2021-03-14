//
// Created by hewro on 2021/3/14.
//
#include "Util.hpp"
class UF {

public:
    std::vector<int> parent;

    explicit UF(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    //p->q 关系
    void union_node(int p,int q){
        std::cout << "union_node " << "p:" << p << " q:" << q <<std::endl;

        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;
        parent[rootQ] = rootP;
    }


    //找到 x 所在树的根节点
    int find(int x) {
        if(parent[x] != x){ //x 的父亲节点不是根节点，则递归把 x放到树的根节点上
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

};
int getVirusRoot(int n, std::set<int> keys,std::unordered_map<int,vector<int>> node_connection){
    std::set<int> keys_copy(keys.begin(),keys.end());

    UF uf(n);
    for (auto pair: node_connection){
        int root = pair.first;
        for (int i = 0; i < pair.second.size(); ++i) {
            uf.union_node(root,pair.second[i]);
        }
    }

    //keys 用 set 的原因是多个节点的父亲节点在循环中有相同的，需要去重只保留一个
    while (keys.size() > 1){//最后肯定可以变成一个 key
        int size = keys.size();
        std::unordered_set<int> temp;
        while (size > 0){
            int key = *keys.begin();
            temp.insert(uf.parent[key]);
            keys.erase(key);
            size--;
        }
        std::copy(temp.begin(),temp.end(),std::inserter(keys,keys.begin()));
    }

    int root = *keys.begin();
    while (keys_copy.count(root) > 0){
        root = uf.parent[root];
    }

    return root;

}
int main(){

    int n = 4;
    std::set<int> keys{2,3};
    std::unordered_map<int,vector<int>> connection{
            {0,{1,2}},
            {1,{3}}
    };

    std::cout << getVirusRoot(n,keys,connection) << std::endl;



}