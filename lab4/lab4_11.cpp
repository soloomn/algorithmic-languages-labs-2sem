#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;


// ��������������� �����, ����������� ���� ����:
class TreeNode
{
	friend class Tree; /* �������� ����� ������ ���� �������� �������������, ����� �� ���� ������ � ��������� ���� */
	// �������� ������:
	double data;
	TreeNode* lPtr;
	TreeNode* rPtr;
public:
	// �����������:
	TreeNode(int d)
	{
		data = d; lPtr = NULL; rPtr = NULL;
	}
};

// �������� �����:
class Tree
{
	TreeNode* rootPtr; // ��������� �� �������� ���� (������� ������)
	// �������� �������:
	void Add(TreeNode*&, int); // ��������� ����� �������
	void inOrder(TreeNode*); // ���������������� �����
	double get_node(TreeNode*);

public:
	// �����������:
	Tree() { rootPtr = NULL; }
	// �������� �������, ������� ����� ������������ ������� ���������:	
	void Add(int);
	void inOrder();
	double get_node();
	const Tree& operator ~ ();
};

// ����������� �������:
//�������, ������� ��������� ���� � ������:
void Tree::Add(int m)
{
	Add(rootPtr, m);
	/* ����� � ����� ���������� ������� ���������, ��������� ������� ��������� �� ����� ������� � ��������� ���� ������, ������� ������������ ���������� ����� ������ ������� Add() � �������� ����� ��������� ����. */
}
/* �������� �������, ������� ������� ������ � ����������� ����� ���� � ������: */
void Tree::Add(TreeNode*& ptr, int m)
{
	if (!ptr)
		/* ���� ������� ��������� ����� 0, � ���� ����������� ����� ����
		��� ������� �������� */
		ptr = new TreeNode(m);
	/* ��������� ����, ��� �������� ptr �������� ��� ������ �� ���������, ��������������� �������� ��������� �� �������� ���� ��� ���������� �������� ��������� � ��� ����, � �������� ������������� ����� */
	else
	{
		if (m < ptr->data) Add(ptr->lPtr, m);
		// ���� ����� ������� ������ �������� � ������� ����, ���� ������ 
		else if (m > ptr->data) Add(ptr->rPtr, m);
		// � ��������� ������ - �������
		// ���� ����������� ������������� ��������, �� ���  ������������, ��������� ����� ��� �������� ������ ����� �������� 
	}
}

// ���������������� �����
void Tree::inOrder()
{
	inOrder(rootPtr);
}

// ����� � ������� �����������:
void Tree::inOrder(TreeNode* ptr)
{
	if (ptr)
	{
		inOrder(ptr->rPtr);
		cout << ptr->data << " ";
		inOrder(ptr->lPtr);
	}
}

double Tree::get_node()
{
	return get_node(rootPtr);
}

double Tree::get_node(TreeNode* ptr)
{
	return ptr->data;
}

istream& operator >> (istream& is, Tree& obj)
{
	int n;
	double nd;

	cout << "������� ����� ����������� ����� " << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "������� ����: ";
		is >> nd;
		obj.Add(nd);
	}

	return is;
}



// ������ ������������� ������:
int main()
{
	//��������� ������� � ������������ ����������: 
	if (SetConsoleCP(1251) == 0)
		//�������� ������������ ��������� ��������� �������� ��� �����
	{
		cerr << "Fialed to set codepage!" << endl;
	}
	if (SetConsoleOutputCP(1251) == 0)//���� ����� ��� ������
	{
		cerr << "Failed to set OUTPUT page!" << endl;
	}
	ifstream opfl("numbers.txt");
	Tree tree; // ��������� ������
	double x;
	// ��������� ���� � �������:
	
	if (opfl)
	{
		cout << "��������� ������������������: \n";
		do
		{
			opfl >> x;
			if (!opfl.eof())
			{
				cout << x << " ";
				tree.Add(x); // ��������� ������� � ������
			}

		} while (!opfl.eof());

		cout << endl;

		cout << "�������� ��������� ����: " << endl;
		double a = tree.get_node();
		cout << a << endl;
		cout << "���������� � �����: " << endl; 
		tree.inOrder();
		cout << endl;
		cin >> tree;
		cout << endl;
		tree.inOrder();

	}
	else cout << "���� �� ������\n";
	_getch();
	return 0;
}
