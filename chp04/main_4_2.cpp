#include <iostream>
#include "MyConstants.h"

using namespace std;

// ���漱�� : extern(al) �� �ٸ� cpp���Ͽ����� �ش� ����� �� �� �ִ�. 
extern void doSomething();
//extern int a;

int main()
{
	// cpp ������ �ٸ� �� constants ���ӽ����̽��� ��������� �ּҰ� �ٸ��ٴ� �� �� �� �ִ�.
	// �׷��� header ���Ͽ� ���� �صΰ� cpp ���Ͽ� �����ؼ� ���� �������ָ� ���� �ּҸ� ���´�.
	cout << "In main.cpp file " << Constants::pi << " �ּ�: " << &Constants::pi << endl;
	doSomething();
	return 0;
}