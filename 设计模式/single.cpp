//
// Created by hewro on 2021/3/31.
//

#include "Util.hpp"
class Test{
private:
    static Test * instance;
    std::mutex mutex_;
public:
    //构造函数，析构函数应该对外不可见
    Test(int i) {};//拷贝构造函数和拷贝赋值运算符应该显式删除
    Test(Test &other) = delete;
    void operator=(const Test &) = delete;
//    Test* getInstance(){
//        std::lock_guard<std::mutex> lock(mutex_);
//        if (instance == nullptr){
//            instance = new Test();
//        }
//        return instance;
//    }
};

//static Test test;

int main(){


}
