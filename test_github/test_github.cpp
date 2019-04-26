#include "Add.h"
#include <iostream>

int main(){

    int a = 2, b = 5, d;

    Add tmp;
    d = tmp.AddNum(a, b);
    std::cout << "AddNum:" << d << std::endl;
    system("pause");
    return 0;
}
