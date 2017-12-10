#pragma once
class FirstClass
{
private:
	int a;
	int& a1;
	const int b;
	static int c;
	int* d;
	const int* e;
public:
	FirstClass(int la, int lb, int ld, int* le);
	virtual ~FirstClass();
	void printAll();
};

