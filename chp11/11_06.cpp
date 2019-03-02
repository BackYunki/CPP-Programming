#include <iostream>
using namespace std;

class Base
{
protected:
	int m_value;

public:
	Base(const int & value) : m_value(value)
	{

	}

	void setValue(int value)
	{
		m_value = value;
	}
};

class Derived : Base
{
public:
	Derived(int value) : Base(value)
	{

	}

	void setValue(int value)
	{
		Base::m_value = value;
	}
};