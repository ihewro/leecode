#pragma once
/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/11
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */
#include "Util.hpp"
#define SIZE 20
class UF {

public:
    // 记录树的数目
    int count;
    // 节点 x 的节点是 parent[x]，存储森林的数据结构
    std::vector<int> parent;
    //存储每棵数目的节点数目，优化1，减少连接时候的树的高度
    vector<int> size;
public:

    explicit UF(int n) {
        this->count = n;
        size.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {//初始化，每个节点都是一颗树，自然每棵树的大小就是1
            parent[i] = i;
            size[i] = 1;
        }
    }

    /* 将 p 和 q 连接 */
    virtual void union_node(int p,int q){
        std::cout << "union_node " << "p:" << p << " q:" << q <<std::endl;

        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;
        //连接两棵树
        if (size[rootQ] < size[rootP]){
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }else{
            parent[rootP] = rootQ;
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


    virtual int find(int x) {
        // 根节点的 parent[x] == x
        while (parent[x] != x){
            parent[x] = parent[parent[x]];//优化2  如这样的结构，对x=3 ,操作结果就是3放到2的父亲上面，1-2-3  --> 1-2 1-3
            x = parent[x];
        }
        return x;
    }

};