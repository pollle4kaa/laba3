#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <memory>
#include <cstdlib>
#include <crtdbg.h>

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //Создаем объект (владелец - shared_ptr)
    auto first = std::make_shared<int>(123);

    //Создаем наблюдателя (weak_ptr)
    std::weak_ptr<int> second = first;

    //Проверяем, жив ли объект
    if (auto temp = second.lock()) {
        std::cout << "Object is alive. value: " << *temp << std::endl;
    }
    else {
        std::cout << "Object has died" << std::endl;
    }

    //Удаляем основной указатель
    first.reset();

    //Проверяем снова
    if (auto temp = second.lock()) {
        std::cout << "Object is still alive" << std::endl;
    }
    else {
        std::cout << "Object has died :(" << std::endl;
    }

    return 0;
}