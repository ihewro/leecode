#include <iostream>
#include <utility>
#include <vector>
#include <string>

class Test{
public:
    std::string i;
    std::string j;
    Test(const Test&){
        std::cout << "copy construct" << std::endl;
    }
    Test(std::string  i){
        std::cout << "direct construct" << std::endl;
        this->i  = i;
    }
};


void func(Test t){};
int main()
{

    Test t = Test("1");//直接初始化，显式调用构造函数
    Test t2 (t);
//    Test t3 = (std::string) "222";
//    Test t4 = {"222"};
//    func((std::string)("1"));

}