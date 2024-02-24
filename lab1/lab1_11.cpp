#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <string.h>
#include <iso646.h>
#include <ctype.h>
using namespace std;

class String1
{
    string st1;
public:
    void set_st1(string stt1) { st1 = stt1; } // access to private class elements
    void input(); 
    void output();
    int sumcs();
};

void String1::input()
{
    cout << "set the string: ";
    cin >> st1;
}

void String1::output()
{
    cout << st1 << endl;
}

int String1::sumcs()
{
    int sum = 0;
    for (int i = 0; i < int(st1.size());i++) // size() seems safer than lenght()
    {
        if (isdigit(st1[i])) // don't care about Undefined Behavior from isdigit() because we clearly define what we are typing
        {
            sum = sum + st1[i] - 48; // don't bother: standard translation via ASCII, where 0 is [48]
        }
    }
    return sum;
}

int mainlab1()
{
    String1 a;
    a.input();
    a.output();
    cout << a.sumcs() << endl;

    _getch(); //the standard windows terminal sometimes closes automatically after code execution, with the empty command "_getch()"
	//let's put it in "standby mode" before entering any character via <Enter> (if you use the standard MS VS Code terminal, this command can be removed)
    return 0;
}