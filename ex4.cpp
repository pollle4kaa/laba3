#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <memory>
#include <cstdlib>
#include <crtdbg.h>

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //������� ������ (�������� - shared_ptr)
    auto first = std::make_shared<int>(123);

    //������� ����������� (weak_ptr)
    std::weak_ptr<int> second = first;

    //���������, ��� �� ������
    if (auto temp = second.lock()) {
        std::cout << "Object is alive. value: " << *temp << std::endl;
    }
    else {
        std::cout << "Object has died" << std::endl;
    }

    //������� �������� ���������
    first.reset();

    //��������� �����
    if (auto temp = second.lock()) {
        std::cout << "Object is still alive" << std::endl;
    }
    else {
        std::cout << "Object has died :(" << std::endl;
    }

    return 0;
}