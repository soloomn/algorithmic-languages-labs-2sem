#include <iostream>
#include <conio.h>
#include <windows.h>
#define _USE_MATH_DEFINES 
#include <math.h>
using namespace std;

class Circle
{
	// Data Elements:
	float r;
	/* friendly input and output functions (these functions must be friendly because the left operand of an operation is a reference to a stream, not a circle): */
	friend istream& operator >> (istream&, Circle&);
	friend ostream& operator << (ostream&, const Circle&);
	// functions - class members:
public:
	// constructors:
	// two in one: main constructor and default constructor
	Circle(float rr = 5) : r(rr) {}
	Circle(const Circle &); //copy constructor
	// destructor:
	~Circle(){}
	// access functions:
	void Set_r(float rr) { r = rr; }
	float Get_r() { return r; }
	// functions - class members that provide input/output:
	void input();
	void output();
	// transaction overload:
	// assignment operation = :
	Circle& operator = (const Circle &);
	// bitwise negation operation ~ :
	const Circle& operator ~ ();
	// logical negation ! :
	const Circle& operator ! ();
};
// function definition:

// assignment operator overloading:
Circle& Circle::operator = (const Circle &obj)
{
	if (this != &obj) // check for self-assignment (like c1 = c1;)
	{ /* in this case, simply the data elements of the object to the left of the assignment sign (this) become equal to the data elements of the object to the right of the assignment sign (obj) */
		r = obj.r;
	}
	return *this; /* function returns the current object, this will allow multiple assignments of the type c1 = c2 = c3 */
}

// logical negation operator overloading

const Circle& Circle::operator ! ()
{
	auto dl = M_PI*r*r;
	return dl; // is responsible for the area of the circle
}

// bitwise negation operator overloading

const Circle& Circle::operator ~ ()
{
	auto pl = 2*M_PI*r;
	return pl; // is responsible for the length of the circle
}

// defining friendly I/O functions:
istream& operator >> (istream& is, Circle& obj)
{
	do
	{
		cout << "Set r:" << endl;
		is >> obj.r;
	} while (obj.r<0);
	return is;
}

ostream& operator << (ostream& os, const Circle& obj)
{
	os << "Value of r:" << obj.r << endl;
	return os;
}

// copy constructor:
Circle::Circle(const Circle& obj)
{
	r = obj.r;
}

// class member functions for input and output:
void Circle::input()
{
	cout << "Set r:" << endl;
	cin >> r;
}

void Circle::output()
{
	cout << "Value of r:" << r << endl;
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
