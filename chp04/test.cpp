#include <iostream>
#include "MyConstants.h"

extern int a = 1;

void doSomething()
{
	using namespace std;
	cout << "In test.cpp " << Constants::pi << " �ּ�: " << &Constants::pi << endl;
}