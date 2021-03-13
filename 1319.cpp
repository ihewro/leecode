/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/23
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */
#include "Util.hpp"

class UF{
public:
    vector<int> parents;
    vector<int> sizes;
    int count = 0;

public:
    UF(int count){
        this->count = count;
        //init
        sizes.resize(count);
        parents.resize(count);
        for (int i = 0; i < count; i++) {//��ʼ����ÿ���ڵ㶼��һ��������Ȼÿ�����Ĵ�С����1
            parents[i] = i;
            sizes[i] = 1;
        }
    }

    int find(int p){
        while (parents[p] !=p){
            parents[p] = parents[parents[p]];
            p = parents[p];
        }
        return p;
    }

    bool unionNode(int p,int q){
        int parent_p = find(p);
        int parent_q = find(q);

        if (parent_p == parent_q){
            return false;
        }

        if (sizes[parent_p] < sizes[parent_q]){
            parents[parent_p] = parent_q;
            sizes[parent_q] += sizes[parent_p];
        }else{
            parents[parent_q] = parent_p;
            sizes[parent_p] += sizes[parent_q];
        }

        this->count --;
        return true;

    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UF uf(n);
        int extra = 0;
        for (auto pair:connections) {
            bool ret = uf.unionNode(pair[0],pair[1]);
            if (!ret){
                extra++;
            }
        }

        std::cout << "count:" << uf.count << " extra:" << extra << std::endl;
        if (extra >= uf.count-1){
            return uf.count-1;
        }else{
            return -1;
        }



    }
};


int main(){
    int n = 100;
    vector<vector<int>> connections{
            {17,51},{33,83},{53,62},{25,34},{35,90},{29,41},{14,53},{40,84},{41,64},{13,68},{44,85},{57,58},{50,74},{20,69},{15,62},{25,88},{4,56},{37,39},{30,62},{69,79},{33,85},{24,83},{35,77},{2,73},{6,28},{46,98},{11,82},{29,72},{67,71},{12,49},{42,56},{56,65},{40,70},{24,64},{29,51},{20,27},{45,88},{58,92},{60,99},{33,46},{19,69},{33,89},{54,82},{16,50},{35,73},{19,45},{19,72},{1,79},{27,80},{22,41},{52,61},{50,85},{27,45},{4,84},{11,96},{0,99},{29,94},{9,19},{66,99},{20,39},{16,85},{12,27},{16,67},{61,80},{67,83},{16,17},{24,27},{16,25},{41,79},{51,95},{46,47},{27,51},{31,44},{0,69},{61,63},{33,95},{17,88},{70,87},{40,42},{21,42},{67,77},{33,65},{3,25},{39,83},{34,40},{15,79},{30,90},{58,95},{45,56},{37,48},{24,91},{31,93},{83,90},{17,86},{61,65},{15,48},{34,56},{12,26},{39,98},{1,48},{21,76},{72,96},{30,69},{46,80},{6,29},{29,81},{22,77},{85,90},{79,83},{6,26},{33,57},{3,65},{63,84},{77,94},{26,90},{64,77},{0,3},{27,97},{66,89},{18,77},{27,43}
    };

    Solution solution;
    std::cout << solution.makeConnected(n,connections) << std::endl;
}