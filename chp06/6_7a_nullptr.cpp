#include <iostream>

using namespace std;

// �Ű������� �������� ��
void doSomething(double *parameter)
{
	cout << "parameter address = " << (int)parameter << endl;
	// cout << "parameter address = " << (int)&parameter << endl; // �������� �ּ��̸� 2�� ������??
	cout << "value = " << *parameter << endl;
}

// �Ű������� �Ϲ� ������ ��
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