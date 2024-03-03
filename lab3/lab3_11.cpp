#include <iostream>
#include <conio.h>
#include <windows.h>
#define _USE_MATH_DEFINES 
#include <math.h>
using namespace std;

class Circle
{
	// �������� ������:
	float r;
	/* ������������� ������� ����� � ������ (��� ������� ������ ���� ������ ��������������, ��������� ����� ��������� �������� �������� ������ �� �����, � �� ����������): */
	friend istream& operator >> (istream&, Circle&);
	friend ostream& operator << (ostream&, const Circle&);
	//������� � ����� ������:
public:
	//������������:
	// ��� � �����: �������� ����������� � ����������� �� ���������
	Circle(float rr = 5) : r(rr) {}
	Circle(const Circle &); //����������� �����������
	//����������:
	~Circle(){}
	// ������� �������:
	void Set_r(float rr) { r = rr; }
	float Get_r() { return r; }
	// ������� � ����� ������, �������������� ����-�����:
	void input();
	void output();
	// ���������� ��������:
	// �������� ������������ = :
	Circle& operator = (const Circle &);
	// �������� ���������� ��������� ~ :
	const Circle& operator ~ ();
	// �������� ����������� ��������� ! :
	const Circle& operator ! ();
};
// ����������� �������:

// ���������� ��������� ������������:
Circle& Circle::operator = (const Circle &obj)
{
	if (this != &obj) // �������� �� ���������������� (���� �1 = �1;)
	{ /* � ������ ������ ������ �������� ������ ���� �������, ������� ����� ������ ����� �� ����� ������������ (this), ���������� ������� ��������� ������ �������, ������� ����� ������ ������ �� ����� ������������ (obj) */
		r = obj.r;
	}
	return *this; /* ������� ���������� ������� ������, ��� �������� ��������� ������������� ������������ ���� c1 = c2 = c3 */
}

// ���������� ��������� ����������� ���������

const Circle& Circle::operator ! ()
{
	auto dl = M_PI*r*r;
	return dl; // �������� �� ������� �����
}

// ���������� ��������� ���������� ���������

const Circle& Circle::operator ~ ()
{
	auto pl = 2*M_PI*r;
	return pl; // �������� �� ����� ����������
}

// ����������� ������������� ������� �����-������:
istream& operator >> (istream& is, Circle& obj)
{
	do
	{
		cout << "������� r:" << endl;
		is >> obj.r;
	} while (obj.r<0);
	return is;
}

ostream& operator << (ostream& os, const Circle& obj)
{
	os << "�������� r:" << obj.r << endl;
	return os;
}

// ����������� �����������:
Circle::Circle(const Circle& obj)
{
	r = obj.r;
}

// �������-����� ������ ��� ����� � ������:
void Circle::input()
{
	cout << "������� r:" << endl;
	cin >> r;
}

void Circle::output()
{
	cout << "�������� r:" << r << endl;
}

// ������ ���������, ������� ���������� ����� Circle:
int main()
{
	//��������� ������� � ������������ ����������: 
	if (SetConsoleCP(1251) == 0)
		//�������� ������������ ��������� ��������� �������� ��� �����
	{
		cerr << "Fialed to set codepage!" << endl;
		/* ���� �� ������� ���������� ������� ��������, ����� ��������� �� ������ */
	}
	if (SetConsoleOutputCP(1251) == 0)//���� ����� ��� ������
	{
		cerr << "Failed to set OUTPUT page!" << endl;
	}
	Circle a;
	//������ ������������� ��������� ������������:
	//a.output();
	Circle b(4.7);
	//b.output();
	//  ������ ������������� ������������ �����������:
	Circle c(b);
	//c.output();
	//������ ������������� �������� ������������:
	b = a;
	//b.output();
	//������ ������������� ������������� ������� �����-������:
	//cin >> c;
	//cout << c;
	// ������ ���������� ������� �������:
	//a.input();
	//a.output();
	float rr;
	cout << "������� �������� r:" << endl;
	cin >> rr;
	// �������� ��������� �����������:
	a.Set_r(rr);
	cout << "�������� r=" << a.Get_r() << endl;
	//a.output(); // ������ ������������� �������������� �������:
	cout << "������� ���������� a: ";
	cout << !a;
	cout << "����� ���������� �: ";
	cout << ~a;
	_getch();
	return 0;
}
