#include "point.h"
#define _USE_MATH_DEFINES 
#include <math.h>

// �����, ����������� �������������:
class rectangle : public Point // ����� Point �������� ������� ��� ������ Rectangle
{
	friend istream& operator >> (istream& is, rectangle& c)
	{
		cout << "������� ���������� ������� �� ������� �� ���� ";
		return is >> c.x >> c.y;
	}
	friend ostream& operator << (ostream& os, const rectangle& c)
	{
		return os << "���������� ������: \n" << Point(0, 0) << Point(c.x, 0) << Point(0, c.y) << Point(c.x, c.y);
		// ������ ������������� ������� �������� ������
	}
	//----------------------------------------------------------------
public:
	// �����������:
	rectangle(double _x = 0, double _y = 0) : Point(_x, _y)
	{
		x = _x;
		y = _y;
	};
	// ����������� �����������:
	rectangle(const rectangle& c) { x = c.x; y = c.y; };
	double okr()
	{
		double l;
		l = x*x + y*y;
		return 2 * M_PI * sqrt(l)/2;
	}
};
