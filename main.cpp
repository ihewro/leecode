#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>
std::mutex mt1;
std::mutex mt2;

volatile bool ok = true;
volatile bool no = false;


bool getOk(){
    std::unique_lock<std::mutex>lock1(mt1);
    return ok;
}

bool getNo(){
    std::unique_lock<std::mutex>lock(mt2);
    return no;
}

void setNo(){
    std::unique_lock<std::mutex>lock(mt2);
    no = true;
}

void setYes(){
    std::unique_lock<std::mutex>lock1(mt1);
    ok = false;
}

void deadLock()
{
    std::cout << "deadLock begin" << std::endl;
    getOk() ;

//    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    getNo();
    std::cout << "deadLock end" << std::endl;

}

void deadLock2()
{
    std::cout << "deadLock2 begin" << std::endl;
    getNo();
//    std::this_thread::sleep_for(std::chrono::milliseconds(15));

    getOk();
    std::cout << "deadLock2 end" << std::endl;

}


void deadLock3()
{
    std::cout << "deadLock3 begin" << std::endl;
    setNo();
    std::cout << "deadLock3 end" << std::endl;

}

int main() {
    std::thread t1([&] {deadLock(); });
    std::thread t2([&] {deadLock2(); });
    std::thread t3([&] {deadLock3(); });
    t1.detach();
    t2.detach();
    t3.detach();

    while (true){

    }
}