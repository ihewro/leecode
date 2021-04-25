//
// Created by hewro on 2021/4/22.
//
#include "Util.hpp"
template <typename T>
class Blob{
public:
    typename vector<T>::size_type  sizeType;

    template<typename R>
    void echo(R val){
        std::cout << val << std::endl;
    }

    void print(T val);
};

template<typename T>
void Blob<T>::print(T val) {}

int main(){
    Blob<int> b{};
    b.sizeType = 20;
    std::cout << b.sizeType << std::endl;
    b.echo("20");

    std::mutex lock;

}
