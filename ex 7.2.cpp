#include <iostream>
#include <string>
#include <regex>
#include <locale>

int main() {
    // Устанавливаем локаль для поддержки кириллицы
    setlocale(LC_ALL, "Russian");

    // Попросим пользователя ввести имя
    std::cout << "Введите своё имя: ";
    std::string name;
    std::getline(std::cin, name);

    // Проверим корректность имени с помощью регулярного выражения
    std::regex nameRegex("^[A-ZА-Я][a-zA-Zа-яА-Я]{1,31}$"); // от 2 до 32 символов, только буквы, первая заглавная
    if (std::regex_match(name, nameRegex)) {
        std::cout << "Имя корректно!" << std::endl;
    }
    else {
        std::cout << "Некорректное имя. Имя должно быть от 2 до 32 символов и начинаться с заглавной буквы." << std::endl;
    }

    // Создадим строку с произвольным текстом, содержащим e-mail адреса
    std::string text = "Контакты: info@example.com, support@domain.ru, user123@company.org. "
        "Вы также можете связаться через secondary.email@service.com.";

    // Регулярное выражение для поиска e-mail адресов
    std::regex emailRegex(R"((\w+([.-]?\w+)*@\w+([.-]?\w+)*\.\w+))");

    // Ищем и выводим все e-mail адреса
    std::smatch match;
    std::string::const_iterator searchStart(text.cbegin());
    std::cout << "Найденные e-mail адреса:" << std::endl;
    while (std::regex_search(searchStart, text.cend(), match, emailRegex)) {
        std::cout << match[0] << std::endl; // match[0] содержит найденный e-mail
        searchStart = match.suffix().first; // продолжаем поиск после последнего найденного совпадения
    }

    return 0;
}