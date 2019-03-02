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
		//���� �ڵ� �����ص� �ǰ�~ �׷��� ������? ����
		//Digit temp(m_digit);
		//++(*this);
		//return temp;
		Digit temp(m_digit);
		++m_digit;	// ��� ��� �ٿ��� �Ȱ���.
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