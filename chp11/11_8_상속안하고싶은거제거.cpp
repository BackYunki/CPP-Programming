#include <iostream>
using namespace std;

class Base
{
private:
	int m_i;
public:
	Base(int in_i) : m_i(in_i) {}

	void print()
	{
		cout << "I'm base" << endl;
	}
};

class Derived : public Base
{
private:
	double m_d;
	using Base::print; // Base Ŭ������ print�� ������ �� ���� �Ѵ�.
public:
	Derived(int in_i) : Base(in_i)
	{
	}
private:
	void print() = delete;
};

int main()
{
	Derived d(7);
	// d.print(); ���ڸ������� �۵�������, ������ �Ұ����ϴ�.

	return 0;
}