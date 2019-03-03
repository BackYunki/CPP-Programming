#include <iostream>
using namespace std;
class Base
{
private:
	int m_data;
public:
	Base(const int & in_data = 0) : m_data(in_data) {}
	virtual void print()
	{
		cout << "Base::" << m_data << '\n';
	}
};

class Derived : public Base
{
private:
	int m_data;
public:
	Derived(const int & in_data = 0) : m_data(in_data) {}
	void print() override
	{
		cout << "Derived::" << m_data << '\n';
	}
};

int main()
{
	Derived d; 

	Base  b1 =  d;
	Base* b2 = &d;
	Base& ref = d;

	b1.print();
	(*b2).print();
	ref.print();

	Base b3;
	cout << sizeof(b1) << endl;
	cout << sizeof(*b2) << endl;
	cout << sizeof(ref) << endl;
	cout << sizeof(b3) << endl;
	cout << sizeof(d) << endl;
	return 0;
}