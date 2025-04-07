#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <iostream>
int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    int* a = new int[1000];
    a[0] = 123;  //Используем память
    std::cout << "Leak: " << a[0];
    return 0;
}