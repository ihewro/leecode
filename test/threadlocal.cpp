//
// Created by hewro on 2021/4/8.
//

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <random>

static thread_local unsigned int rage = 1;
std::mutex cout_mutex;

void increase_rage(const std::string& thread_name)
{
    sleep(5);
    ++rage; // 在锁外修改 OK；这是线程局域变量
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << thread_name << " 的愤怒计数：" << rage << '\n';
}

inline void random_uniform_float(float *const dst, const int len, const int min = 0, const int max = 1)
{
    // generator is only created once in per thread, but distribution can be regenerated.
    thread_local std::default_random_engine generator;     // heavy
    std::uniform_real_distribution<float> distribution(min, max); // light
    for (int i = 0; i < len; ++i)
    {
        dst[i] = distribution(generator);
    }
}


//int main()
//{
////    std::thread a(increase_rage, "a"), b(increase_rage, "b");
////
////
////
////    a.detach();
////    b.detach();
////
////    {
////        sleep(8);
////        std::lock_guard<std::mutex> lock(cout_mutex);
////        std::cout << "main 的愤怒计数：" << rage << '\n';
////    }
////
////    while (1){
////
////    }
//
//    float dst[10];
//    random_uniform_float(dst,10,0,10);
//    for (int i = 0; i < 10; ++i) {
//        std::cout << dst[i] << " ";
//    }
//}

class B {
public:
    B() {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "create B" << std::endl;
    }
    ~B() {}
    thread_local static int b_key;
    //thread_local int b_key;
    int b_value = 24;
    static int b_static;
};

 thread_local int B::b_key = 12;
int B::b_static = 36;

void thread_func(const std::string& thread_name) {
    B b;
    for (int i = 0; i < 3; ++i) {
        b.b_key--;
        b.b_value--;
        b.b_static--;   // not thread safe
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "thread[" << thread_name << "]: b_key:" << b.b_key << ", b_value:" << b.b_value << ", b_static:"
                  << b.b_static << std::endl;
        std::cout << "thread[" << thread_name << "]: B::key:" << B::b_key << ", b_value:" << b.b_value << ", b_static: "
                  << B::b_static << std::endl;
        return;
    }
}
int main() {
    std::thread t1(thread_func, "t1");
    std::thread t2(thread_func, "t2");
    t1.join();
    t2.join();
    return 0;
}