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
	using Base::print; // Base 클래스의 print에 접근할 수 없게 한다.
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
	// d.print(); 인텔리센스가 작동하지만, 접근은 불가능하다.

	return 0;
}