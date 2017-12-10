#pragma once
#include "FirstClass.h"
#include <iostream>
using namespace std;

class SecondClass :	public FirstClass {

public:
	SecondClass(int la, int lb, int ld, int* le) :FirstClass(la, lb, ld, le) {
		cout << "Constructor @SecondClass@ called.\n";
	};
	~SecondClass()
	{
		cout << "Destructor @SecondClass@ called.\n";
	}
};

