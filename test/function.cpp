//
// Created by hewro on 2021/3/18.
//

#include "Util.hpp"
//加法，普通函数
int add(int i,int j){return i + j;};

//减法，lambda 表达式
auto reduce = [](int i,int j){return i - j;};

//乘法，类的调用运算符重载
struct plus{
    int operator ()(int i,int j){return i * j;}
};

//除法，函数指针
int divide_ (int i,int j){return i/j;}
int (*divide) (int i,int j);

//模运算,bind 创建
class Util{
public:
    int mod(int i, int j){return i % j;};
};
Util util;
auto mod_ = std::bind(&Util::mod,util,std::placeholders::_1,std::placeholders::_2);

//std::function
std::function<int(int,int)> mod = mod_ ;

int t[10]{1,11,3,4,5,6,7,8,9,10};
//int (*func(int i)) [10] {
//    int * tt = t;
//    int(*test)[10] = t;
//    return test;
//}
int add2(int i,int j){return i+j;};
auto ad2d(int i,int j)->int {return i+j;}
int main(){
    int *x = t;
    int(*test)[10] = &t;
    int *p2 = (int*)&t;


//    int ** tt = &t_;
    std::cout << (*test) << std::endl;

    std::cout << (*x) << std::endl;
    std::cout << (*p2) << std::endl;
}