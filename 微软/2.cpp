#include "bits/stdc++.h"
class UF {

public:
    // 记录树的数目
    int count;
    // 节点 x 的节点是 parent[x]，存储森林的数据结构
    std::vector<int> parents;
    //存储每棵数目的节点数目，优化1，减少连接时候的树的高度
    vector<int> size;
public:

    explicit UF(int n) {
        this->count = n;
        size.resize(n);
        parents.resize(n);
        for (int i = 0; i < n; i++) {//初始化，每个节点都是一颗树，自然每棵树的大小就是1
            parents[i] = i;
            size[i] = 1;
        }
    }

    /* 将 p 和 q 连接 */
    virtual void union_node(int p,int q){
//        std::cout << "union_node " << "p:" << p << " q:" << q <<std::endl;

        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;
        //连接两棵树
        if (size[rootQ] < size[rootP]){
            parents[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }else{
            parents[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        //树的数目减少1
        count--;
    }

    /* 判断 p 和 q 是否连通 */
    virtual bool connected(int p, int q){
        int p_parent = find(p);
        int q_parent = find(q);

        std::cout << "p:" << p << " q:"<< q << " p_parent:" << p_parent << "  q_parent:" << q_parent << std::endl;

        return p_parent == q_parent;
    }


    //找到 x 所在树的根节点
    virtual int find(int x) {
        if(parents[x] != x){ //x 的父亲节点不是根节点，则递归把 x放到树的根节点上
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

};

int solution(vector<int> &T, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    UF uf(T.size());
    std::unordered_set<int> need;
    for (int i = 0; i < A.size(); ++i) {
        uf.union_node(A[i],T[A[i]]);
        //T[A[i]]和父节点进行连接
        int tmp = T[A[i]];
        while(tmp!=0){
            uf.union_node(tmp,T[tmp]);
            tmp = T[tmp];
        }
    }

    int root = uf.find(A[0]);

    return uf.size[root];
}




int main(){
    vector<int> T{0,0,1,1};
    vector<int> A{2};
    std::cout << solution(T,A);
}
