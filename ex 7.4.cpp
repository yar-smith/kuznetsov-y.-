#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <locale> // для работы с локалями

// Функция для вывода элементов вектора
void printVector(const std::vector<float>& vec) {
    for (float element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// Класс Settings для работы с настройками
class Settings {
public:
    // Статическое поле типа Map
    static std::map<std::string, std::string> settingsMap;

    // Статическая функция для добавления пары ключ-значение в Map
    static void Add(const std::string& key, const std::string& value) {
        settingsMap[key] = value;
    }

    // Статическая функция для получения значения по ключу из Map
    static std::string Get(const std::string& key) {
        if (settingsMap.find(key) != settingsMap.end()) {
            return settingsMap[key];
        }
        return "Ключ не найден";
    }

    // Статическая функция для вывода содержимого Map в консоль
    static void Print() {
        for (const auto& pair : settingsMap) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }
};

// Определение статического поля класса Settings
std::map<std::string, std::string> Settings::settingsMap;

int main() {
    // Устанавливаем локаль для поддержки кириллицы (8-битная кодировка)
    setlocale(LC_ALL, "Russian");

    // 1. Создаем пустой вектор с типом float
    std::vector<float> vec;

    // 2. Добавляем 5 элементов в вектор
    vec.push_back(1.1);
    vec.push_back(2.2);
    vec.push_back(3.3);
    vec.push_back(4.4);
    vec.push_back(5.5);

    // 3. Вызов функции для вывода вектора
    std::cout << "Вектор после добавления 5 элементов: ";
    printVector(vec);

    // 5. Вставка элемента между 3 и 4 элементами
    vec.insert(vec.begin() + 3, 3.75);

    // 6. Проверка правильности вставки
    std::cout << "Вектор после вставки элемента между 3 и 4 элементами: ";
    printVector(vec);

    // 7. Удаление последнего элемента
    vec.pop_back();

    // 8. Проверка правильности удаления
    std::cout << "Вектор после удаления последнего элемента: ";
    printVector(vec);

    // 9-15. Работа с классом Settings
    // Проверка работы статических методов и поля
    Settings::Add("volume", "70");
    Settings::Add("brightness", "90");
    Settings::Add("resolution", "1920x1080");

    std::cout << "\nЗначение 'volume': " << Settings::Get("volume") << std::endl;
    std::cout << "Значение 'brightness': " << Settings::Get("brightness") << std::endl;

    std::cout << "\nСодержимое Map:" << std::endl;
    Settings::Print();

    return 0;
}