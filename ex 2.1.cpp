﻿//1.    Получите от пользователя 2 числа.
//
//2.    Выведите среднее арифметическое двух введённых чисел в консоль.
//
//3.    Попросите пользователя ввести знак операции : +, -, * или / .
//
//4.    Сохраните эту команду в переменную.
//
//5.    Используя условный оператор, выполните соответствующую операцию с двумя ранее введёнными числами.То есть, если, например, пользователь ввёл*, то надо вывести результат перемножения этих чисел.
//
//6.    Закомментируйте код из предыдущего пункта и реализуйте его с использованием оператора switch - case.

#include <iostream>
#include <string>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	int n;
	int a;
	std::cin >> n;
	std::cin >> a;
	std::cout << (a + n) / 2;
	char str;
	std::cout << u8"Введите один из знаков +, -, * или /\n";
	std::cin >> str;
	switch (str) {//принимаем значение переменной
	case '+'://проверка на случай если это +
		std::cout << a + n;//выводим сумму
		break;//заканчиваем этот кейс
	case '-'://если пользователь ввел -
		std::cout << a - n; // в этом случае выводим разность
		break;// Заканчиваем кейс
	case '*':// если пользователь ввелд*
		std::cout << a * n; // Вывводим произведение
		break;// Заканчиваем этот кейс
	case '/':// Если пользователь ввел /
		std::cout << a / n;// выводим результат деления
		break;

	}
}
