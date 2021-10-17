#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>
#include "bits/stdc++.h"

#define N 2


int main()
{
    string s1 = "abab";
    string s2 = "aba";
    int p =  (s1 + s1).find(s1, 1);
    printf("%s中%s出现的下标索引为%d\n其中子串为: %s, 重复次数为 : %d\n",
           (s1 + s1).c_str(), s1.c_str(), p, s1.substr(0, p).c_str(), s1.size() / p);
    std::cout << std::endl;
    printf("%s中%s出现的下标索引为%d \n", (s2 + s2).c_str(), s2.c_str(), (s2 + s2).find(s2, 1));

    return 0;
}
