#include <string>
#include <iostream>
#include "Constants.h"

extern void doSomething();

int main()
{
	using namespace std;
	using Constants::PI;

	cout << "main.cpp : Hello!\n";
	cout << "main.cpp : PI = " << PI << " 파이값의 주소: " << &Constants::PI << endl;
	cout << "\n";
	doSomething();

	return 0;
}