#include "Weapon.h"
#include <iostream>
using namespace std;

int main() {
    // Создание двух объектов оружия
    Weapon weapon1("Sword", 20, 3.0);
    Weapon weapon2("Shield", 5, 7.5);

    // Вывод информации о каждом объекте
    weapon1.displayInfo();
    weapon2.displayInfo();

    // Использование метода, принимающего объект, который теперь вызывает перегруженную версию
    double totalWeight1 = weapon1.getTotalWeight(weapon2);
    cout << "\nTotal Weight of Weapon1 and Weapon2: " << totalWeight1 << " kg" << endl;

    // Использование перегруженного метода для получения суммарного веса объекта и дополнительного веса
    double totalWeight2 = weapon1.getTotalWeight(2.0); // Например, добавляем вес 2.0 кг
    cout << "Total Weight of Weapon1 and additional weight: " << totalWeight2 << " kg" << endl;

    return 0;
}