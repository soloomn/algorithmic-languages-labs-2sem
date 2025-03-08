#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
using namespace std; 
#define DEFSET 100 // Размер множества по умолчанию

// 5.11. Разработать шаблонный класс Set для работы с множеством символов. Класс должен содержать конструктор по умолчанию, основной конструктор и конструктор копирования. 
// Перегрузить в этом классе операторные функции, которые обеспечивают ввод/вывод элементов класса, а также  операторную функцию присваивания. 
// Перегрузить также операторные функции - и -=, которые должны обеспечивать исключение из первого множества тех элементов, которые имеются во втором множестве. 
// Создать с помощью этого класса множество чисел.

template <class Stype> class Set  // Stype – условное название типа элементов
{
	// закрытые функции:
	void insert(Stype member);  // добавление элемента
	void remove(Stype member);  // удаление элемента
	int find (Stype member);    // возвращение индекса элемента
	int ismember (Stype member); //проверка, является ли элемент членом множества

	public:
    
    int NumMembers; // Количество элементов множества
    Stype *SetPtr; //  Указатель на члены множества
	int MemSize;   //  Размер памяти, выделенный множеству

    template<typename stype> friend istream& operator >> (istream& stream, Set &ob); // операторы ввода
	template<typename stype> friend ostream& operator << (ostream& stream, Set &ob); // оператор вывода

	Set(); // конструктор по умолчанию
	Set (int size); // основной конструктор 
	Set (const Set& ob); // конструктор копирования
	~Set() { delete SetPtr;} // деструктор

	//Операторные функции:
	Set<Stype>& operator = (const Set<Stype> &ob); // присваивание
	Set<Stype> operator - (Set<Stype> &ob); // Разность множеств
    Set<Stype>& operator + (Stype member); // Добавление нового элемента

	operator int () {return NumMembers;} //операция преобразования к типу int
};

//определение функций:

template <class Stype> Set<Stype> :: Set() // конструктор по умолчанию
{
	SetPtr = new Stype[DEFSET]; // используем размер по умолчанию
	if (!SetPtr)
	{
		cout <<"Ошибка при размещении объекта в памяти.\n";
	    exit(1);
	}
	NumMembers = 0; // множество пока пустое
	MemSize = DEFSET;
}

template <class Stype> Set<Stype> :: Set(int size)  // основной конструктор (создает пустое множество c областью памяти заданного размера)
{
	SetPtr = new Stype[size]; 
	if (!SetPtr)
	{
		cout <<"Ошибка при размещении объекта в памяти.\n";
		exit(1); 
	}
	NumMembers = 0;
	MemSize = size;
}

template <class Stype> Set<Stype> :: Set(const Set<Stype> &ob) // конструктор копирования
{
	MemSize = ob.MemSize;
	SetPtr = new Stype[MemSize]; // выделяем память для копии
	if (!SetPtr)
	{
		cout<<"Ошибка выделения памяти \n";
		exit(1);
	}
	NumMembers = ob.NumMembers;
	for (int  i=0; i<NumMembers; i++) // копируем элементы множества
		SetPtr[i] = ob.SetPtr[i];
}


template <class Stype> int Set <Stype> :: find (Stype member) // функция осуществляет поиск элемента во множестве и возвращает номер этого элемента
{
	for (int i=0; i< NumMembers; i++)
		if (SetPtr[i] == member) return i;
	return -1; // если элемент не найден, функция возвращает –1
}

template <class Stype> int Set <Stype> :: ismember(Stype member) // функция проверяет, входит ли элемент во множество
{
	if (find(member) != -1) return 1;
	else return 0;
}

template <class Stype> void Set <Stype> :: insert(Stype member) // основная функция, которая добавляет элемент во множество
{
	if (NumMembers == MemSize) // если множество заполнено
	{
		Stype* tmp = new Stype[MemSize+10];  // выделяем новую память большего размера и копируем туда элементы:
		
        for (int i =0; i< NumMembers; i++)
			tmp[i] = SetPtr[i];
		
        delete []SetPtr; // освобождаем ранее выделенную память
		SetPtr = tmp; // настраиваем указатель на новую область памяти
	}
	
    if (! ismember(member)) // если элемент еще не входит во множество
	{
		int i=0;
		while (i<NumMembers && SetPtr[i]<member) i++; // находим для него место
		for (int j = NumMembers-1; j>=i; j--)
			SetPtr[j+1] = SetPtr[j]; // сдвигаем элементы от этого места вправо
		SetPtr[i] = member; // вставляем элемент
		NumMembers++;
	}
}


template <class Stype> 
void Set<Stype> :: remove(Stype member) // функция удаляет заданный элемент
{
	int loc = find(member); // определяеи номер этого элемента
	if ( loc != -1) // если элемент входит во множество
	{
		for(; loc<NumMembers-1; loc++)
			SetPtr[loc] = SetPtr[loc+1]; // сдвигаем элементы влево
		NumMembers--;
	}
}


template <class Stype> 
istream& operator >> (istream& stream, Set<Stype> &ob) // функция ввода элементов
{
	Stype member;
	int k;
	cout << "Сколько элементов определить? ";
	cin >> k;
	cout << "Задайте элементы множества \n";
	for (int i=0; i< k; i++)
	{
		cout << i+1 << " --> ";
		stream >> member;
		ob = ob + member; // используем нижеследующую операторную функцию +
	}
	return stream;
}


template <class Stype> 
ostream& operator << (ostream& stream, Set<Stype> &ob) // функция вывода элементов
{
	stream << "{ ";
	for (int i=0; i<ob.NumMembers; i++)
		stream << ob.SetPtr[i] << " ";
	stream << " }" << endl;
	return stream;
}

// Оператор присваивания:
template <class Stype>
Set<Stype>& Set<Stype>:: operator = (const Set<Stype>& ob)
{
    if (SetPtr == ob.SetPtr) return *this; // если выполняется самоприсваивание, функция завершает свою работу

	MemSize = ob.MemSize; // в противном случае выполнчется копирование объекта ob
	delete []SetPtr;
	SetPtr = new Stype[MemSize];
	NumMembers = ob.NumMembers;

	for (int i=0; i<NumMembers; i++)
		SetPtr[i] = ob.SetPtr[i]; // копирование элементов
	return *this  ;
}

template <class Stype>
Set<Stype> Set<Stype>:: operator - (Set<Stype>& ob) // функция удаляет из первого множества те элементы, которые есть во втором 
{
	Set<Stype> temp(*this);
	for (int i=0; i < ob.NumMembers; i++)
		if (ismember(ob.SetPtr[i]))
	temp.remove(ob.SetPtr[i]);
	return temp;
}

template <class Stype>
Set<Stype>& Set<Stype>:: operator + (Stype member) // операция добавления элемента к множеству
{
	insert(member);
	return *this;
}



int main()
{
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

	Set <int> s;
    cout << "Первое множество:" << endl;
	cin >> s;
	cout << s;
	s = s + 1 + 3 + -1;
	cout << "Добавили 1, 3, -1:" << endl ;
	cout << s;
	
    Set<int> s1;
	s1 = s1 + 1 + 5 + 10;
	cout << "Второе множество:" << endl;
	cout << "s1 = " << s1;

	cout<< "Разность множеств:" << endl;
    s = s - s1;
	cout << s;

	_getch();
	return 0;
}
