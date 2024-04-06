#include <iostream>
using namespace std;

// �����, ����������� �����:
class Point
{
protected:
	double x, y;
private:
	//---------------------------------------------------------
	friend istream& operator >> (istream& is, Point& p)
	{
		cout << "������� ���������� ����� ";
		return is >> p.x >> p.y;
	}
	friend ostream& operator << (ostream& os, const Point& p)
	{
		return os << "��������� �����: [" <<
			p.x << ", " << p.y << "]\n";
	}
	//----------------------------------------------------------------
public:
	Point(double _x = 0, double _y = 0)
	{
		x = _x; y = _y;
	}
};
