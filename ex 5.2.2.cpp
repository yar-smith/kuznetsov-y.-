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

// Абстрактный класс Оружие
class Weapon {
protected:
    string name;
    int damage;
    WeaponType type;

public:
    // Конструктор
    Weapon(string name, int damage, WeaponType type)
        : name(name), damage(damage), type(type) {}

    // Чисто виртуальная функция для атаки
    virtual void Attack() const = 0;

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

    // Реализация метода Attack
    void Attack() const override {
        cout << "Атакуем магическим оружием" << endl;
    }

    // Переопределённый метод для отображения информации о магическом оружии
    void displayWeaponInfo() const override {
        Weapon::displayWeaponInfo();
        cout << "Дополнительный урон: " << additionalDamage << endl;
    }
};

// Класс одноразового оружия (дочерний от класса Weapon)
class SingleUseWeapon : public Weapon {
private:
    bool used;

public:
    // Конструктор с параметрами
    SingleUseWeapon(string name, int damage, WeaponType type)
        : Weapon(name, damage, type), used(false) {}

    // Реализация метода Attack
    void Attack() const override {
        if (used) {
            cout << "Оружие уже было использовано" << endl;
        }
        else {
            cout << "Атакуем одноразовым оружием" << endl;
            const_cast<SingleUseWeapon*>(this)->used = true; // Изменяем флаг использования
        }
    }
};

// Шаблонный класс для хранения оружия в левой и правой руке
template <typename LeftHandWeapon, typename RightHandWeapon>
class WeaponHolder {
private:
    LeftHandWeapon leftHand;
    RightHandWeapon rightHand;

public:
    // Конструктор
    WeaponHolder(LeftHandWeapon left, RightHandWeapon right) : leftHand(left), rightHand(right) {}

    // GET-методы
    LeftHandWeapon getLeftHand() const {
        return leftHand;
    }

    RightHandWeapon getRightHand() const {
        return rightHand;
    }

    // SET-методы
    void setLeftHand(LeftHandWeapon left) {
        leftHand = left;
    }

    void setRightHand(RightHandWeapon right) {
        rightHand = right;
    }
};

// Основная функция для тестирования
int main() {
    // Установка локали для поддержки кириллицы
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Тестируем класс MagicWeapon
    MagicWeapon magicWeapon;
    magicWeapon.displayWeaponInfo();
    magicWeapon.Attack();

    // Тестируем класс SingleUseWeapon
    SingleUseWeapon singleUseWeapon("Граната", 100, WeaponType::ONEHANDED);
    singleUseWeapon.displayWeaponInfo();
    singleUseWeapon.Attack();
    singleUseWeapon.Attack(); // Проверяем повторное использование

    // Тестируем шаблонный класс WeaponHolder
    WeaponHolder<MagicWeapon, int> weaponHolder(magicWeapon, 42); // 42 может быть id оружия
    cout << "Левая рука держит: ";
    weaponHolder.getLeftHand().displayWeaponInfo();
    cout << "Правая рука имеет ID: " << weaponHolder.getRightHand() << endl;

    return 0;
}