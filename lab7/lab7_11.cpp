#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include "rectangle.h"
using namespace std;

// 7.11 Разработать класс Point для задания координаты точки на плоскости.Выбирая этот класс в качестве базового класса, разработать производный класс Rectangle, 
// определяющий различные прямоугольники со сторонами, параллельными осям координат.Определить в этом классе функцию, возвращающую длину окружности, описанной вокруг данного прямоугольника.
// В обоих классах объявить виртуальную функцию Length, которая возвращает длину соответствующего объекта. 
// В главной программе объявить массив указателей на несколько точек и несколько прямоугольников. Вывести в длину окружности, описанной вокруг первого прямоугольника.

int mainlab7_11()
{
	//Настройки шрифтов и региональных стандартов: 
	if (SetConsoleCP(1251) == 0)
		//проверка правильности установки кодировки символов для ввода
	{
		cerr << "Fialed to set codepage!" << endl;
		/* если не удалось установить кодовую страницу, вывод сообщения об ошибке */
	}
	if (SetConsoleOutputCP(1251) == 0)//тоже самое для вывода
	{
		cerr << "Failed to set OUTPUT page!" << endl;
	}
	Point** ptr = new Point*[5]; /* помните, что указатель на объект производного класса является одновременно и указателем на объект базового класса */
	// создаем несколько объектов:	
	ptr[0] = new Point(100, 100);
	ptr[1] = new rectangle(200, 200);
	ptr[2] = new Point(100, 200);
	ptr[3] = new rectangle(200, 250);
	ptr[4] = new Point(100, 300);
	/* такого типа цикл можно написать только при использовании виртуальных функций: */
	for (int i = 0; i<5; i++)
		cout << "Длина объекта " << ptr[i]->Length() << endl;
	// одним оператором обрабатываем объекты разных типов
	//------------------------------------
	cout << "длина окружности описанной около первого прямоугольника: " << endl;
	cout << ptr[1]->okr();
	for (int i = 0; i<5; i++)
		delete ptr[i];
	delete ptr;
	_getch();
	return 0;
}