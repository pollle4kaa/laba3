#include <iostream>
#include <memory> //��� unique_ptr
#include <fstream>

class ForFile {
    std::unique_ptr<std::fstream> file; //��������� �� ����
public:
    //����������� ��������� ����
    ForFile(const std::string& filename) {
        file = std::make_unique<std::fstream>(filename);
        if (!file->is_open()) {
            throw std::runtime_error("Error: File was not open");
        }
        std::cout << "File open" << std::endl;
    }

    //��������
    bool isOpen() const {
        return file && file->is_open();
    }
    //���������� �� �����, ���� ��������� ��� ��������� unique_ptr
};

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    {
        std::unique_ptr<int[]> a(new int[1000]);
        a[0] = 123;  //���������� ������
        std::cout << "no leak: " << a[0] << std::endl;
    }

    try {
        ForFile f("C:/Users/user/Downloads/test.txt"); //��������� ����
        if (f.isOpen()) {
            std::cout << "Success" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "������: " << e.what() << std::endl;
    }
    //������ ������������� ����������� ��� ������ �� ������� ���������
    return 0;
}

