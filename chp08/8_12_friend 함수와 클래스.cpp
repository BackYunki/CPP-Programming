#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>
using namespace std;
/*
	������ �����ε����� �����带 ���� ����.
	�����ϰ� ���� Ŭ���� �ۿ��� ��������� �����ϱ� ���� ������ �ִ� �뵵�� ����.
	Ŭ���� ������ friend �� �ٿ��� ������ Ÿ���� ����� �ۿ��� �� �Լ��� �����ϸ� �ȴ�.
*/

class A;

class B
{
private:
	int m_value = 2;

public:
	void doSomething(A& a);
	//{ cout << a.m_value << endl; } <- ���⼱ A�� �˾Ƶ� ��������� �� �� ����.
	// �׷��� ���⼱ ������Ÿ�Ը� ����� �Ʒ����� �������ָ� �ȴ�.
	// �̰� ����� ������ �и���� �Ѵ�.
};

class A
{
private:
	int m_value = 1;

	//friend class B; <- ��°�� �����ִ� �� �� �δ㽺����.
	friend void B::doSomething(A& a);
};

void B::doSomething(A& a)
{
	cout << a.m_value << endl;
}

int main()
{
	A a;
	B b;
	b.doSomething(a);

	return 0;
}