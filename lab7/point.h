#include <iostream>
using namespace std;

// Класс, описывающий точку:
class Point
{
protected:
	int x, y;
private:
	//---------------------------------------------------------
	/*friend istream& operator >> (istream& is, Point& p)
	{
		cout << "Задайте координаты точки ";
		return is >> p.x >> p.y;
	}
	friend ostream& operator << (ostream& os, const Point& p)
	{
		return os << "коордиаты точки: [" <<
			p.x << ", " << p.y << "]\n";
	}*/
	//----------------------------------------------------------------
public:
	Point(int _x = 320, int _y = 240) //основной конструктор
	{
		x = _x; y = _y;
	}

	int GetX() { return x; }
	
	virtual double okr(){ return 0; }

	virtual double Length() //Виртуальная функция возвращающая длину. 
		// Для точки - длинна радиус вектора:
	{
		return sqrt((double)(x*x + y*y));
	}

};
