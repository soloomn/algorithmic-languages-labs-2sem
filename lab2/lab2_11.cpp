#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <String.h>
#include <iso646.h>
#include <ctype.h>
#include <stdlib.h>
using namespace std;

class String2
{
    string st;
public:
    String2(string stt) :st(stt){};
    String2(const String2& obj)
    {
        st = obj.st;
    }
    void set_st1(string st1) { st = st1; }
    void input();
    string output();
    string concat(string a, string b);
};

void String2::input()
{
    cout << "set the string: ";
    cin >> st;
}

string String2::output()
{
    return st;
}

string String2::concat(string a, string b)
{
    return a + b;
}

int main()
{
    String2 s1("");
    String2 s2(s1);
    s1.input();
    s2.input();
    cout << s1.output() << endl << s2.output() << endl;
    cout << "concatenation result: " << s1.concat(s1.output(), s2.output());

    _getch(); //the standard windows terminal sometimes closes automatically after code execution, with the empty command "_getch()"
	//let's put it in "standby mode" before entering any character via <Enter> (if you use the standard MS VS Code terminal, this command can be removed)
    return 0;
}