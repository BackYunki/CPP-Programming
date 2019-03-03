#include <iostream>
using namespace std;

class Base
{
public:
	virtual ~Base()
	{
		cout << "~Base()\n";
	}
};

class Derived : public Base
{
private:
	int * m_array;
public:
	Derived(const int & length)
	{
		m_array = new int[length];
	}
	virtual ~Derived() override
	{
		cout << "~Derived" << endl;
		delete [] m_array;
	}
};

int main()
{

	return 0;
}