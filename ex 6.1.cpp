#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>
#include <locale>

// Определим собственное исключение с перечислением кодов ошибок
class BirthYearException : public std::exception {
public:
    enum ErrorCode {
        YEAR_TOO_OLD,
        YEAR_IN_FUTURE,
        NEGATIVE_YEAR
    };

    BirthYearException(ErrorCode code) : code(code) {}

    const char* what() const noexcept override {
        switch (code) {
        case YEAR_TOO_OLD:
            return "Что-то не верится...";
        case YEAR_IN_FUTURE:
            return "Вы ещё не родились";
        case NEGATIVE_YEAR:
            return "Вы ввели отрицательное число!";
        default:
            return "Неизвестная ошибка";
        }
    }

private:
    ErrorCode code;
};

// Функция для преобразования числа в текст
std::string numberToText(int number) {
    switch (number) {
    case 1: return "Один";
    case 2: return "Два";
    case 3: return "Три";
    default: throw std::invalid_argument("Некорректное значение");
    }
}

// Функция для проверки года рождения
void checkBirthYear(int year) {
    int currentYear = std::time(0) / (60 * 60 * 24 * 365.25) + 1970; // получение текущего года

    if (year < 1850) {
        throw BirthYearException(BirthYearException::YEAR_TOO_OLD);
    }
    else if (year > currentYear) {
        throw BirthYearException(BirthYearException::YEAR_IN_FUTURE);
    }
    else if (year < 0) {
        throw BirthYearException(BirthYearException::NEGATIVE_YEAR);
    }
    else {
        std::cout << "Спасибо!" << std::endl;
    }
}

int main() {
    // Устанавливаем локаль для поддержки кириллицы
    setlocale(LC_ALL, "Russian");

    try {
        std::cout << "Введите число 1, 2 или 3: ";
        int num;
        std::cin >> num;
        std::cout << numberToText(num) << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "Введите год своего рождения: ";
        int birthYear;
        std::cin >> birthYear;
        checkBirthYear(birthYear);
    }
    catch (const BirthYearException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}