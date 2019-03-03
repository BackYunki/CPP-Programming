#include <iostream>

using namespace std;

// 매개변수가 포인터일 때
void doSomething(double *parameter)
{
	cout << "parameter address = " << (int)parameter << endl;
	// cout << "parameter address = " << (int)&parameter << endl; // 포인터의 주소이면 2중 포인터??
	cout << "value = " << *parameter << endl;
}

// 매개변수가 일반 변수일 때
void doSomething(double parameter)
{
	cout << "parameter address = " << (int)&parameter << endl;
	cout << "value = " << parameter << endl;
}

int main()
{
	double argument = 1.0f;
	cout << "argument address = " << (int)&argument << endl;
	cout << "value = " << argument << endl;

	//doSomething(&argument);
	doSomething(argument);
}