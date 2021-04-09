#include <unistd.h>
using namespace std;
#include "iostream"
int main() {
    for (int i = 0; i < 2; i ++){
        fork();
//        printf("ok ");
        std::cout << "ok ";
    }
}