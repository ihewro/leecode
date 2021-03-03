/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/3
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"


class UF{
public:
    //b = 2a parents[b] = a; weight[b] = 2; parent[i] = y ���� i��y��N����
    std::unordered_map<string,string> parents{};
    std::unordered_map<string,double> weights{};//value��ʾkey = value * parent[key]


    //p = weight * q
    void union_node(string p, string q,double weight){
        auto root_p = find(p);
        auto root_q = find(q);

        if (root_p == root_q){
            return ;//�Ѿ������˹�ϵ
        }
        // p = weight * q
        // p = weights[p] * root_p
        // q = weights[q] * root_q
        // root_p = weights[root_p] x root_q
        parents[root_p] = root_q;
        weights[root_p] = 1.0 * weight * weights[q] / weights[p];
    }
    string find(string p,bool isQuery=false) {
        //�ڵ�Ĭ���������������
        if (parents.count(p) <=0 ){
            if (isQuery){
                return "";
            }else{
                parents[p] = p;
                weights[p] = 1;
            }
        }

        if (parents[p] != p){
            // a= 2b b= 2c  ->  a = 4c
            //parents[a] = b; parents[b] = c -> weight[a] = weight[a] * weight[parent[a]] ;parent[a] = parent[parent[a]]
            //�޸�weights
            auto origin_parent = parents[p];
            parents[p] = find(parents[p]);// a= 2b b= 2c ->  a= weight[a] * weight[b] * c
            weights[p] = weights[p] * weights[origin_parent];
        }
        return parents[p];

    }


    double isConnected(string p, string q){
        auto ret_p = find(p,true);
        auto ret_q = find(q,true);

        if (ret_p.empty() || ret_q.empty() || ret_q != ret_p){
            return -1.0;
        }else{
            return weights[p] / weights[q];
        }

    }
};
class Solution {
public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        vector<double> ret{};

        UF uf;
        for (int i = 0; i < equations.size(); ++i) {
            auto equation_ = equations[i];
            uf.union_node(equation_[0],equation_[1],values[i]);
        }


        for (auto query_:queries){
            string p = query_[0];
            string q = query_[1];

            ret.push_back(uf.isConnected(p,q));

        }

        return ret;

    }
};
int main() {
    Solution solution;

    vector<vector<string>> equations = {{"a","b"},{"b","c"},{"c","d"},{"d","e"}};
    vector<double> values = {2,2,2,2,2};
    vector<vector<string>> queries = {{"a","e"}};

    auto ret =solution.calcEquation(equations, values, queries);
    vector_util::print(ret);
}