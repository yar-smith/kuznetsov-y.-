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
protected:
    string name;
    int damage;
    WeaponType type;

public:
    // Конструктор
    Weapon(string name, int damage, WeaponType type)
        : name(name), damage(damage), type(type) {}

    // Виртуальный метод для получения урона
    virtual int getDamage() const {
        return damage;
    }

    // GET-метод для типа оружия
    WeaponType getType() const {
        return type;
    }

    // Метод для получения имени оружия
    string getName() const {
        return name;
    }

    // Виртуальный метод для отображения информации об оружии
    virtual void displayWeaponInfo() const {
        cout << "Оружие: " << name << ", Урон: " << getDamage()
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

    // Переопределение операторов сравнения по урону
    bool operator>(const Weapon& other) const {
        return this->getDamage() > other.getDamage();
    }

    bool operator<(const Weapon& other) const {
        return this->getDamage() < other.getDamage();
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

    // Переопределённый метод для получения урона
    int getDamage() const override {
        return damage + additionalDamage;
    }

    // Переопределённый метод для отображения информации о магическом оружии
    void displayWeaponInfo() const override {
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

    // Тестируем класс MagicWeapon
    MagicWeapon magicWeapon1;
    magicWeapon1.displayWeaponInfo();

    MagicWeapon magicWeapon2("Магический посох", 40, WeaponType::TWOHANDED, 20);
    magicWeapon2.displayWeaponInfo();

    // Проверка оператора > и <
    if (magicWeapon2 > weapon) {
        cout << magicWeapon2.getName() << " сильнее, чем " << weapon.getName() << endl;
    }
    else {
        cout << weapon.getName() << " сильнее, чем " << magicWeapon2.getName() << endl;
    }

    if (magicWeapon1 < magicWeapon2) {
        cout << magicWeapon1.getName() << " слабее, чем " << magicWeapon2.getName() << endl;
    }
    else {
        cout << magicWeapon2.getName() << " слабее, чем " << magicWeapon1.getName() << endl;
    }

    return 0;
}