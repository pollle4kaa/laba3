#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <memory>
#include <cstdlib>
#include <crtdbg.h>
int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::shared_ptr<int> ptr1 = std::make_shared<int>(123);
    {
        std::shared_ptr<int> ptr2 = ptr1;
        std::cout << "number of owners: " << ptr1.use_count() << std::endl;
        std::cout << "number of owners: " << ptr2.use_count() << std::endl;
    }
    std::cout << "value: " << *ptr1 << std::endl;
    std::cout << "number of owners: " << ptr1.use_count() << std::endl;

    return 0;
}