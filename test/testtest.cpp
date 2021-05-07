#include "iostream"
using namespace std;

class A {
public:
    void PrintA()  {
        cout << "A";
    }
//    virtual void PrintA()  {
//        cout << "A";
//    }
};

class B {
public:
    void PrintB()  {
        cout << "B";
    }
//    virtual void PrintB()  {
//        cout << "B";
//    }
};

int main(){
    A* pa = new A();
    B* pb = (B*)pa;
    pb->PrintB();
}