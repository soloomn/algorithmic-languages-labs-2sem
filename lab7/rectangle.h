#include "point.h"
#define _USE_MATH_DEFINES 
#include <math.h>

// Класс, описывающий прямоугольник:
class rectangle : public Point // Класс Point является базовым для класса Rectangle
{
	/*friend istream& operator >> (istream& is, rectangle& c)
	{
		cout << "Задайте координаты вершины не лежащей на осях ";
		return is >> c.x >> c.y;
	}
	friend ostream& operator << (ostream& os, const rectangle& c)
	{
		return os << "координаты вершин: \n" << Point(0, 0) << Point(c.x, 0) << Point(0, c.y) << Point(c.x, c.y);
		// Пример использования функции базового класса
	}*/
	//----------------------------------------------------------------
public:
	// конструктор:
	rectangle(int _x = 0, int _y = 0) : Point(_x, _y)
	{
		x = _x;
		y = _y;
	};
	// Конструктор копирования:
	rectangle(const rectangle& c) { x = c.x; y = c.y; };
	
	double okr() // функция отвечает за нахождение длины описанной окружности
	{
		double l;
		l = x*x + y*y;
		return 2 * M_PI * sqrt(l)/2;
	}
	double Length() { return 2*(x+y); } // периметр прямоугольника
};
