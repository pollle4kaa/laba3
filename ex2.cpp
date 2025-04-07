#include <iostream>
#include <memory> //Для unique_ptr
#include <fstream>

class ForFile {
    std::unique_ptr<std::fstream> file; //Указатель на файл
public:
    //Конструктор открывает файл
    ForFile(const std::string& filename) {
        file = std::make_unique<std::fstream>(filename);
        if (!file->is_open()) {
            throw std::runtime_error("Error: File was not open");
        }
        std::cout << "File open" << std::endl;
    }

    //Проверка
    bool isOpen() const {
        return file && file->is_open();
    }
    //Деструктор не нужен, файл закроется сам благодаря unique_ptr
};

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    {
        std::unique_ptr<int[]> a(new int[1000]);
        a[0] = 123;  //Используем память
        std::cout << "no leak: " << a[0] << std::endl;
    }

    try {
        ForFile f("C:/Users/user/Downloads/test.txt"); //Открываем файл
        if (f.isOpen()) {
            std::cout << "Success" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    //Память автоматически освободится при выходе из области видимости
    return 0;
}

