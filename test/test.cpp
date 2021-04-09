//
// Created by hewro on 2021/3/21.
//

#include "Util.hpp"

void test(){
    static int aa = 20;
    aa ++;
    std::cout << aa << std::endl;
}

class Test{
public:
    static const int a;

    static void te(){

    }
};
int main(){
//    std::unordered_map<int,int>map;
//    map[1] = 20;

    test();
    test();
    test();
    test();

}