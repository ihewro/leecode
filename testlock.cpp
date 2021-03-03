/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/14
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

std::mutex mutexA;
std::mutex mutexB;
using std::cout ;
using std::endl ;
void WaitDeadLockThread1() {
    mutexA.lock();   //A
    std::cout << "WaitDeadLockThread1, and want lock mutexA" << std::endl;


    mutexB.lock();   //B

}


int main() {

    mutexA.lock();
    std::cout << "main thread mutexA.locked " << std::endl;
    std::thread t1([&] {WaitDeadLockThread1(); });
    t1.detach();
    cout << "当前线程: 正在等待线程:WaitDeadLockThread1执行完成！" << endl;
    cout << "main thread wait finish" << endl;

    while (true){

    }
}