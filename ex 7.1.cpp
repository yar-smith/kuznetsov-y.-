#include <iostream>
#include <string>
#include <locale>

int main() {
    // Устанавливаем локаль для поддержки кириллицы
    setlocale(LC_ALL, "Russian");

    // Попросим пользователя ввести строку
    std::cout << "Введите строку: ";
    std::string userInput;
    std::getline(std::cin, userInput);  // Используем getline для ввода всей строки

    // Проверим, что длина строки позволяет вывести подстроку от 2-го до 4-го символа включительно
    if (userInput.length() >= 4) {
        std::string substring = userInput.substr(1, 3); // 1 - индекс второго символа, 3 - количество символов
        std::cout << "Подстрока от 2-го до 4-го символа: " << substring << std::endl;
    }
    else {
        std::cout << "Строка слишком короткая для выделения подстроки от 2-го до 4-го символа." << std::endl;
    }

    // Найдем индекс первого вхождения символа 'a' в строку
    size_t index = userInput.find('a');
    if (index != std::string::npos) {
        std::cout << "Индекс первого вхождения 'a': " << index << std::endl;
    }
    else {
        std::cout << "Символа 'a' не найдено" << std::endl;
    }

    return 0;
}