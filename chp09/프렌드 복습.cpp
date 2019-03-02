#include <iostream>
using namespace std;

class B;

class A
{
private:
	int m_value = 1;

public:
	A(const int& input = 0) : m_value(input) {}
	
	friend void doSomething(const A& a, const B& b);
};

class B
{
private:
	int m_value = 1;

public:
	B(const int& input = 0) : m_value(input) {}

	friend void doSomething(const A& a, const B& b);
};

class C;

class D
{
private:
	int m_value = 1;

public:
	D(const int& input = 0) : m_value(input) {}

	void doSomething(C& c);
};

class C
{
private:
	int m_value = 1;
	//friend class D;
public:
	C(const int& input = 0) : m_value(input) {}

	friend void D::doSomething(C& c);
};

void D::doSomething(C& c)
{
	cout << c.m_value << endl;
}

void doSomething(const A& a, const B& b)
{
	cout << a.m_value << " " << b.m_value << endl;
}


int main()
{
	A a;
	B b;
	doSomething(a, b);

	C c;
	D d;
	d.doSomething(c);

	return 0;
}