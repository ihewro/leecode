//
// Created by hewro on 2021/4/3.
//
#include "Util.hpp"
#include <unistd.h>


typedef  std::function<void (int)> Handle;
//耗时的任务
void task(Handle h){
//    sleep(1);
    int ret = 20;
    h(ret);
}
void request(){
    std::cout << "Request Begin" << std::endl;

    auto handle = [](int ret){
        std::cout << "ret:" << ret << std::endl;
    };
    task(handle);
    std::cout << "Request End" << std::endl;

}
int main(){

}