#include <iostream>
#include "Constants.h"

extern void doSomething()
{
	using namespace std;
	cout << "test.cpp : Hello!\n";
	cout << "test.cpp : PI = " << Constants::PI << " ���̰��� �ּ�: " << &Constants::PI << endl;
}