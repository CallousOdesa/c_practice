#include "../stdafx.h"
#include "firstClass.h"
#include <iostream>
using namespace std;

// Initialisation of static member
int FirstClass::c = 3;
FirstClass::FirstClass(int la, int lb, int ld, int* le) : a1(la), b(lb), e(le) {
	cout << "Constructor @FirstClass@ called.\n";
	a = la;
	
	d = new int(ld);
}


FirstClass::~FirstClass()
{
	cout << "Destructor @FirstClass@ called.\n";
	delete d;
	delete e;
}


void FirstClass::printAll() {
	cout << "a: " << a << " b: " << b << " c: " << c << " d: " << *d << " e: " << *e << "\n";
}