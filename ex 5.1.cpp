#include <iostream>
#include <string>
#include <locale>
#include <codecvt> // Для преобразования в 8-битную кодировку

using namespace std;

// Перечисление для типов оружия
enum class WeaponType {
    ONEHANDED, // Одноручное
    TWOHANDED, // Двуручное
    BOW,       // Лук
    CROSSBOW   // Арбалет
};

// Функция для преобразования строк в 8-битную кодировку
string to8Bit(const wstring& wstr) {
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> convert;
    return convert.to_bytes(wstr);
}

// Класс Оружие
class Weapon {
private:
    string name;
    int damage;
    WeaponType type;

public:
    // Конструктор
    Weapon(string name, int damage, WeaponType type)
        : name(name), damage(damage), type(type) {}

    // GET-метод для типа оружия
    WeaponType getType() const {
        return type;
    }

    // Метод для отображения информации об оружии
    void displayWeaponInfo() const {
        cout << "Оружие: " << name << ", Урон: " << damage
            << ", Тип: " << to8Bit(getTypeDescription()) << endl;
    }

    // Метод для получения текстового описания типа
    wstring getTypeDescription() const {
        switch (type) {
        case WeaponType::ONEHANDED:
            return L"Одноручное оружие";
        case WeaponType::TWOHANDED:
            return L"Двуручное оружие";
        case WeaponType::BOW:
            return L"Лук";
        case WeaponType::CROSSBOW:
            return L"Арбалет";
        default:
            return L"Неизвестный тип";
        }
    }
};

// Структура игрока
struct Player {
    int id;
    string login;
    string password;

    // Метод для вывода информации об игроке
    void displayPlayerInfo() const {
        cout << "ID: " << id << endl;
        cout << "Логин: " << login << endl;
        cout << "Пароль: " << password << endl;
    }
};

// Класс магического оружия (дочерний от класса Weapon)
class MagicWeapon : public Weapon {
private:
    int additionalDamage;

public:
    // Конструктор без параметров
    MagicWeapon()
        : Weapon("Магическое оружие", 50, WeaponType::ONEHANDED), additionalDamage(10) {}

    // Конструктор с параметрами
    MagicWeapon(string name, int damage, WeaponType type, int additionalDamage)
        : Weapon(name, damage, type), additionalDamage(additionalDamage) {}

    // GET-метод для дополнительного урона
    int getAdditionalDamage() const {
        return additionalDamage;
    }

    // Метод для отображения информации о магическом оружии
    void displayWeaponInfo() const {
        Weapon::displayWeaponInfo();
        cout << "Дополнительный урон: " << additionalDamage << endl;
    }
};

// Основная функция для тестирования
int main() {
    // Установка локали для поддержки кириллицы
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Тестируем класс Weapon
    Weapon weapon("Меч", 30, WeaponType::ONEHANDED);
    weapon.displayWeaponInfo();

    // Тестируем структуру Player
    Player player = { 1, "player1", "password123" };
    player.displayPlayerInfo();

    // Тестируем класс MagicWeapon
    MagicWeapon magicWeapon1;
    magicWeapon1.displayWeaponInfo();

    MagicWeapon magicWeapon2("Магический посох", 40, WeaponType::TWOHANDED, 20);
    magicWeapon2.displayWeaponInfo();

    return 0;
}