#include <iostream>
using namespace std;

int g_a = 123;

void doSomething()
{
	static int a = 0;	// ���������� ������ �ּҸ� ���� ����� �ݵ�� �ʱ�ȭ�� �ؾ��Ѵ�.
	++a;				// �� �� �ʱ�ȭ ���ָ� ������ ����ǵ� �ʱ�ȭ ������ ���õȴ�.
	cout << a << endl;	// �� a�� ������ ������ �ܺο��� �����Ϸ��� �����Ͱ� �ʿ��ϴ�.
}

int main()
{
	int a = 1;

	cout << a << endl;
	cout << ::g_a << " " << g_a << endl;	// ::�� ������� ���ٿ��̴�.

	doSomething();
	doSomething();
	doSomething();
	doSomething();
	return 0;
}