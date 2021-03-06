// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "classes/FirstClass.h"
#include "classes/SecondClass.h"
using namespace std;

int main()
{
	cout << "Main ENTER" << "\n";
	int* temp = new int(5);
	FirstClass* f = new FirstClass(1, 2, 4, temp);
	f->printAll();
	// 4 - object pointer + a + a1 + b + c + 4 (Vtable pointer)
	cout << sizeof(*f) << '\n';
	delete f;


	int* temp2 = new int(5);
	FirstClass* s = new SecondClass(1, 2, 4, temp2);
	s->printAll();
	cout << sizeof(*s) << '\n';
	delete s;

	int x;
	cin >> x;
	return 0;
}