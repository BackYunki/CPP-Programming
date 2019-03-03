#include <iostream>
#include "Constants.h"

extern void doSomething()
{
	using namespace std;
	cout << "test.cpp : Hello!\n";
	cout << "test.cpp : PI = " << Constants::PI << " 파이값의 주소: " << &Constants::PI << endl;
}