//
// Created by hewro on 2021/10/17.
//
#include "bits/stdc++.h"

using namespace std;

class Data {
public:
    int index = 0; //盒子种类序号
    int a = 0; // 数目
    int b = 0; // 另一个盒子种类的序号
    long long num = -1; // 糖果的数量
    Data() {};

    Data(int index_, int a_, int b_) : index(index_), a(a_), b(b_) {};
};


long long getNum(vector<Data> &values, int i) {
    if (values[i].num != -1) {
        return values[i].num;
    }
    long long num =  getNum(values, values[i].b) * values[i].a;
    values[i].num = num;
    return num;
};

int main() {
    int n;// 盒子种类数目
    std::cin >> n;
    vector<Data> values(n);
    values[0].num = 1;
    for (int i = 1; i < n; ++i) {
        int a_;
        cin >> a_;
        values[i] = Data(i, a_, -1);
    }

    for (int i = 1; i < n; ++i) {
        int b_;
        cin >> b_;
        values[i].b = b_ - 1;
    }



    for (int i = 0; i < n; ++i) {
        std::cout << (getNum(values, i) % 1000000007) << " ";
    }
    std::cout << std::endl;
}