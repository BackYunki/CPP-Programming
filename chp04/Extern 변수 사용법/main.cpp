#include <string>
#include <iostream>
#include "Constants.h"

extern void doSomething();

int main()
{
	using namespace std;
	using Constants::PI;

	cout << "main.cpp : Hello!\n";
	cout << "main.cpp : PI = " << PI << " ���̰��� �ּ�: " << &Constants::PI << endl;
	cout << "\n";
	doSomething();

	return 0;
}