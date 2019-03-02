#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;

class Cents
{
private:
	int m_cents;
public:
	Cents(const int& cents = 0) : m_cents(cents) {}

	int  getCents() const { return m_cents; }
	int& getCents()		  { return m_cents; }

	/*
		Cents operator + (const Cents &rhs)
		return Cents( this->m_cents + rhs.m_cents );
	*/
	Cents& operator + (const Cents& rhs) 
	{
		m_cents += rhs.m_cents;
		return *this;
	}
};

int main()
{
	Cents cents1(6);
	Cents cents2(8);

	//cout << (cents1+cents2+Cents(6)).getCents() << endl;

	cout << (cents1 + cents2 + Cents(10)) << endl;


	return 0;
}