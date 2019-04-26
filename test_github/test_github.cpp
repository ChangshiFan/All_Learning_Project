#include "get.h"
#include <iostream>

int main(){

    int a = 2, b = 5, d;

    Get tmp;
    d = tmp.square(a, b);
    std::cout << "square:" << d << std::endl;
    system("pause");
    return 0;
}
