#include <iostream>
using namespace std;

class Base
{
public:
	Base() {}

	virtual ostream& print(ostream& out) const
	{
		out << "Base";
		return out;
	}
	friend ostream& operator << (ostream& out, const Base & base)
	{
		return base.print(out);
	}
};

class Derived : public Base
{
public:
	Derived() {}
	virtual ostream& print(ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};

int main()
{
	Base b;
	cout << b << endl;
	Derived d;
	cout << d << endl;

	Base &bref = d;
	cout << bref << endl;

	return 0;
}