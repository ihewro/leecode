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
    // ��¼������Ŀ
    int count;
    // �ڵ� x �Ľڵ��� parent[x]���洢ɭ�ֵ����ݽṹ
    std::vector<int> parent;
    //�洢ÿ����Ŀ�Ľڵ���Ŀ���Ż�1����������ʱ������ĸ߶�
    vector<int> size;
public:

    explicit UF(int n) {
        this->count = n;
        size.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {//��ʼ����ÿ���ڵ㶼��һ��������Ȼÿ�����Ĵ�С����1
            parent[i] = i;
            size[i] = 1;
        }
    }

    /* �� p �� q ���� */
    virtual void union_node(int p,int q){
        std::cout << "union_node " << "p:" << p << " q:" << q <<std::endl;

        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;
        //����������
        if (size[rootQ] < size[rootP]){
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }else{
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        //������Ŀ����1
        count--;
    }

    /* �ж� p �� q �Ƿ���ͨ */
    virtual bool connected(int p, int q){
        int p_parent = find(p);
        int q_parent = find(q);

        std::cout << "p:" << p << " q:"<< q << " p_parent:" << p_parent << "  q_parent:" << q_parent << std::endl;

        return p_parent == q_parent;
    }


    virtual int find(int x) {
        // ���ڵ�� parent[x] == x
        while (parent[x] != x){
            parent[x] = parent[parent[x]];//�Ż�2  �������Ľṹ����x=3 ,�����������3�ŵ�2�ĸ������棬1-2-3  --> 1-2 1-3
            x = parent[x];
        }
        return x;
    }

};