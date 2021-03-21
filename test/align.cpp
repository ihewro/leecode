//
// Created by hewro on 2021/3/19.
//

#include "Util.hpp"

int main(){
    struct student
    {
        char name;
        int num;
        short score;
    };

    struct A{
        int    a;
        char   b;
        short  c;
    };

    A s;
    std::cout << sizeof (s) << std::endl;
}