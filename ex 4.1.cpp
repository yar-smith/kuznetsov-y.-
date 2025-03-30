

#include <iostream>
#include <string>
using namespace std;

class Gun {
private:
    string name;
    int damage;
    int weight;
public:
    Gun(string name, int damage, int weight) {
        this->name = name;
        this->damage = damage;
        this->weight = weight;
    }
    Gun() {
        name = "uzi";
        damage = 12;
        weight = 50;
    }
    void displayInfo() {
        cout << name << endl;
        cout << damage << endl;
        cout << weight << endl;
    }
};

int main()
{
    Gun defoultParam;
    defoultParam.displayInfo();
    Gun customParam("Axe", 25, 59);
    customParam.displayInfo();
}
