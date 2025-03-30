#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <locale>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    // Устанавливаем локаль для поддержки кириллицы
    setlocale(LC_ALL, "Russian");

    // 1. Попросим пользователя ввести радиус окружности
    std::cout << "Введите радиус окружности: ";
    double radius;
    std::cin >> radius;

    // 2. Вычислим и выведем длину окружности с округлением до 3 знаков после запятой
    double circumference = 2 * M_PI * radius;
    std::cout << "Длина окружности: " << std::round(circumference * 1000) / 1000 << std::endl;

    // Переходим на новую строку ввода для бесконечного цикла, считываемого строки
    std::cin.ignore();  // Очистка буфера ввода

    std::string userInput;
    const std::string filename = "output.txt";

    // Бесконечный цикл для обработки строк
    while (true) {
        std::cout << "Введите строку (или 'read', 'erase', 'exit' для действий): ";
        std::getline(std::cin, userInput);

        if (userInput == "read") {
            // Открываем файл для чтения
            std::ifstream file(filename);
            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line)) {
                    std::cout << line << std::endl; // Выводим содержимое файла
                }
                file.close();
            }
            else {
                std::cout << "Ошибка при открытии файла." << std::endl;
            }
        }
        else if (userInput == "erase") {
            // Открываем файл в режиме обнуления содержимого
            std::ofstream file(filename, std::ios::trunc);
            if (file.is_open()) {
                std::cout << "Файл очищен." << std::endl;
                file.close();
            }
            else {
                std::cout << "Ошибка при открытии файла." << std::endl;
            }
        }
        else if (userInput == "exit") {
            // Завершаем программу
            break;
        }
        else {
            // Записываем строку в файл, если она не является командой
            std::ofstream file(filename, std::ios::app);
            if (file.is_open()) {
                file << userInput << std::endl;
                file.close();
            }
            else {
                std::cout << "Ошибка при открытии файла." << std::endl;
            }
        }
    }

    return 0;
}