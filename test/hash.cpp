//
// Created by hewro on 2021/3/21.
//
#include "Util.hpp"
class Test{
public:
    int x;
};


class TestHash
{
public:
    std::size_t operator()(const Test& c) const
    {
        return std::hash<int>()(c.x);
    }
};

std::size_t customer_hash_func(const Test& c)
{
    return std::hash<int>()(c.x);
}
int main(){
//    std::unordered_map<Test,int,std::size_t(*)(const Test&)>> map{};

//    Test t{1};
//    map[t]= 20;

    std::cout <<std::hash<int>()(22)<< std::endl;


}