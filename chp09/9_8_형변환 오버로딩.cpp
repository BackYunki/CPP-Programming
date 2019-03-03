#include <iostream>
using namespace std;
/*
 static_cast 를 오버로딩해서 암시적 형변환을 시켜보자!
*/
class Cents
{
private:
	int m_cents;

public:
	Cents(const int& cents = 0)
	{
		m_cents = cents;
	}

	// 형변환 오버로딩은 (int)var, int(var), static_cast<int>(var); 다 오버로딩 해준다.
	operator int()	
	{
		cout << "Cents cast to Integer: ";
		return m_cents;
	}
	
	int getCents() { return m_cents; }
	void setCents(const int& cents) { m_cents = cents; }
};
void printInt(const int& value)
{
	cout << value << endl;
}

class Dollars
{
private:
	int m_dollars;

public:
	Dollars(const int& dollars) : m_dollars(dollars) {}

	operator Cents()
	{
		return Cents(m_dollars * 100);
	}
};

int main()
{
	Cents cents(7);
/*
	cout << int(cents) << endl;
	cout << (int)cents << endl;
	cout << static_cast<int>(cents) << endl;
*/
	int centsToInt = cents;
	cout << centsToInt << endl;

	Dollars dollars(10);
	cout << Cents(dollars) << endl;

	return 0;
}