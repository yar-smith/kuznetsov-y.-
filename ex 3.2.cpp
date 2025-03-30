//1.       Создайте функцию, которая принимает 2 указателя(на начало и конец массива) и которая возвращает сумму всех элементов массива.
//
//2.       Проверьте правильность работы функции, вызвав её и передав массив из нескольких чисел.
//
//3.       Создайте 2 функции, принимающих 2 параметра и возвращающих их сумму и их разность соответственно.
//
//4.       Создайте функцию, принимающую 1 параметр типа char.
//
//5.       Созданная функция должна возвращать указатель на одну из двух функций(суммы или разности) в зависимости от значения переданного char.Если он равен '+', то возвращается указатель на функцию суммы, а если он равен '-', то возвращается указатель на функцию разности.
//
//6.       Проверьте работу созданных функций, вызвав сначала ту, что возвращает указатель, а потом вызвав и эту функцию по указателю, получив правильное значение, которое затем выведите в консоль.
//
//7.       Создайте динамический указатель типа float.
//
//8.       Выведите его в консоль, а после удалите его из памяти с помощью delete.

#include <iostream>
using namespace std;

int preFunction(int* start, int* end) {
    int sum = 0;
    for (int* ptr = start; ptr != end; ++ptr) {
        sum += *ptr;
    }
    return sum;
}

int sumParam(int count1, int count2) {
    return count1 + count2;
}
int raznParam(int count1, int count2) {
    return count1 - count2;
}

int (*funcChar(char param))(int, int) {
    if (param == '+') {
        return &sumParam;
    }
    else if (param == '-') {
        return &raznParam;
    }
}

int main()
{
    int arr[] = { 1,2,3,4,5 };
    int* start = arr;
    int* end = arr + 5;
    int totalSumm = preFunction(start, end);
    cout << totalSumm << endl;
    int (*param)(int, int) = funcChar('+');
    cout << param(1, 1) << endl;
    float* ptr = new float;
    *ptr = 5.48;
    cout << *ptr;
    delete ptr;


}

