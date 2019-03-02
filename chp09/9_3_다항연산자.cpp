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
	int& getCents() { return m_cents; }

	bool operator ! () const
	{
		return m_cents == 0 ? true : false;
	}

	Cents operator - () const
	{
		return Cents(-m_cents);
	}

	friend Cents operator + (const Cents& lhs, const Cents& rhs)
	{
		return Cents(lhs.m_cents + rhs.m_cents);
	}

	friend ostream& operator << (ostream& out, const Cents& cent)
	{
		out << cent.m_cents;
		return out;
	}
};

int main()
{
	Cents cents1(6), cents2(8);

	cout << cents1 + cents2 + Cents(6) << endl;

	cout << -cents1 << endl;
	cout << -Cents(-10) << endl;

	cout << boolalpha << !Cents(0) << endl;
	cout << !Cents(1) << endl;

	cout << noboolalpha << true << endl;
	
	return 0;
}