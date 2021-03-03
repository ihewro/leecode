/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/19
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include <iostream>
#include <string>
#include <vector>
#include "absl/synchronization/mutex.h"
#include <thread>

absl::Mutex mt1;
absl::Mutex mt2;


void deadLock()
{
    mt1.Lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    mt2.Lock();
}

void deadLock2()
{
    mt2.Lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    mt1.Lock();
}


int main() {
    std::thread t1([&] {deadLock(); });
    std::thread t2([&] {deadLock2(); });

    t1.detach();
    t2.detach();

    while (true){

    }
}