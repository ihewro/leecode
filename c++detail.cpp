/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/24
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#define NDEBUG          // �������У��� assert ������
#include <assert.h>

#pragma pack(8) //����2�ֽڶ���
#include "Util.hpp"
class Test{
public:
    const int a = 2;
    int b = 3;
    Test(){};
    Test(int a_):a(a_){

    };
    void print() const{
//        this->b = 2;
    }
};
int main() {

//    auto t = Test(3);
TreeNode* p = nullptr;
    assert( p != nullptr );    // assert ������

//    int arr[] = int[4];

    int arr[10];
    int* q = arr;
//    std::cout << sizeof (arr) << std::endl;
//    std::cout << sizeof (q) << std::endl;

    char acWelcome[]="1";
    std::cout << sizeof (acWelcome) << std::endl;

    struct student
    {
//        char name[5];
//        int num;
//        short score;
        int mode: 2;    // mode ռ 2 λ

    };

    student s{};

    enum string{
        x1,
        x2,
        x3=10,
        x4,
        x5,
    } x;
    std::cout << x << std::endl;


}