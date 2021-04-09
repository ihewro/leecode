#include<iostream>


class Base {
private:
    virtual void fun() { std::cout << "Base Fun"; }
    friend int main();
};

class Derived: public Base {
public:
    void fun() { std::cout << "Derived Fun"; }
};

int main() {
    Base *ptr = new Derived;
    ptr->fun();//输出  Derived Fun
    return 0;
}