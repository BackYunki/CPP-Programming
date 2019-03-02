#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Digit
{
private:
	int m_digit;

public:
	Digit(const int& digit = 0) : m_digit(digit) {}

	// prefix
	Digit& operator ++ ()
	{
		++m_digit;
		return *this;
	}

	// postfix
	Digit operator ++ (int)
	{
		//위의 코드 응용해도 되고~ 그런데 낭비지? ㅎㅎ
		//Digit temp(m_digit);
		//++(*this);
		//return temp;
		Digit temp(m_digit);
		++m_digit;	// 얘는 어디 붙여도 똑같음.
		return temp;
	}

	Digit& operator --()
	{
		--m_digit;
		return *this;
	}

	Digit operator --(int)
	{
		Digit temp(m_digit);
		--m_digit;
		return temp;
	}

	friend ostream & operator << (ostream &out, const Digit &d)
	{
		out << d.m_digit;
		return out;
	}
};

int main()
{
	Digit d(0);
	cout << d << endl;
	cout << ++d << endl;
	cout << d++ << endl;
	cout << d << endl;
	cout << --d << endl;
	cout << d-- << endl;
	cout << d << endl;

	return 0;
}