#include <iostream>
using namespace std;

class Base
{
public:
	int m_pub;
protected:
	int m_pro;
private:
	int m_pri;
};

class Derived : private Base
{
public:
	Derived()
	{
		Base::m_pub = 1234;
		Base::m_pro = 1234;
	}
};

int main()
{
	Derived derived;

	return 0;
}