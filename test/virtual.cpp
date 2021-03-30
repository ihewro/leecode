//
// Created by hewro on 2021/3/28.
//

#include "Util.hpp"
using namespace std;
#include <iostream>
#include <stdio.h>
using namespace std;

class A{
public:
    int x = 1;
    virtual void b() {}
};

class Base {
public:
    virtual void a() { cout << "Base a()" << endl; }
    virtual void b() { cout << "Base b()" << endl; }
    virtual void c() { cout << "Base c()" << endl; }
};

class Derive : public Base {
public:
    virtual void b() { cout << "Derive b()" << endl; }
    virtual void d() { cout << "Derive d()" << endl; }
};


int main()
{
//    std::cout << sizeof (A) << std::endl;
//    A* p = new A;
//    A* p2 = new A;
//    auto p_x = &(p->x);
//    cout <<p_x << endl;

    typedef void (*Func)();
    cout << "-----------Base------------" << endl;
    Base* q = new Base;
    long* tmp1 = (long*)q;
    long* vptr1 = (long*)(*tmp1);
    for (int i = 0; i < 3; i++) {
        printf("vptr[%d] : %p\n", i, vptr1[i]);
    }
    Func a = (Func)vptr1[0];
    Func b = (Func)vptr1[1];
    Func c = (Func)vptr1[2];
    a();
    b();
    c();

    Base* p2 = new Derive;

    p2->d();
    Derive* p = new Derive;
    long* tmp = (long*)p;
    long* vptr = (long*)(*tmp);
    cout << "---------Derive------------" << endl;
    for (int i = 0; i < 3; i++) {
        printf("vptr[%d] : %p\n", i, vptr[i]);
    }
    Func d = (Func)vptr[0];
    Func e = (Func)vptr[1];
    Func f = (Func)vptr[2];
    d();
    e();
    f();

    union MyUnion{
        int a;
        char c;
    }test;
    test.a = 1;
    if (test.c == 1){
        cout << "little endian" <<endl;
    }else{
        cout << "big endian" <<endl;
    }

    return 0;
}