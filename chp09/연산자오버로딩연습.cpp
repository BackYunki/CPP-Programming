#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
using namespace std;

class Digit
{
private:
	double m_digit;

public:
	Digit(const double& digit = 0) : m_digit(digit) {}

	Digit operator + (const Digit& rhs)
	{ 
		return Digit(m_digit + rhs.m_digit);
	}
	Digit& operator - ()
	{
		m_digit *= -1;
		return *this;
	}
	// prefix
	Digit& operator ++()
	{
		++m_digit;
		return *this;
	}
	// postfix : () 안에 아무거나 더미로 넣으면 된다.
	Digit operator ++(int)
	{
		Digit temp(m_digit);
		++m_digit;	// ++(*this);
		return temp;
	}
	Digit& operator -- ()
	{
		--m_digit;
		return *this;
	}
	Digit operator -- (int)
	{
		Digit temp(m_digit);
		--m_digit;
		return temp;
	}
	bool operator ! ()
	{
		return m_digit == 0 ? true : false;
	}
	bool operator < ( const Digit rhs )
	{
		return m_digit < rhs.m_digit ? true : false;
	}
	friend Digit operator + (const double lhs, Digit& rhs)
	{
		return Digit(lhs + rhs.m_digit);
	}
	friend ostream& operator << (ostream& out, const Digit& digit)
	{
		out << digit.m_digit;
		return out;
	}
	friend istream& operator >> (istream& in, Digit& digit)
	{
		in >> digit.m_digit;
		return in;
	}
	void setDigit(const double& digit)
	{
		m_digit = digit;
	}
};

class DigitVector
{
private:
	vector<Digit> m_list;
public:
	DigitVector(const int& size = 1)
	{
		m_list.resize(size);
		for (size_t i = 0; i < size; i++)
		{
			m_list[i] = Digit(0);
		}
	}

	Digit& operator [] (const int& index)
	{
		return m_list.at(index);
	}
};

int main()
{
	//Digit d1(8);
	//cout << d1 << endl;

	//Digit d2;
	//cin >> d2;

	//cout << d2 + 10 << endl;
	//cout << -(10 + d2) << endl;
	//
	//cout << boolalpha << !Digit(0) << noboolalpha << endl;

	//random_device rd;
	//mt19937 g(rd());

	//vector<Digit> vec(20);
	//for (size_t i = 0; i < vec.size(); i++)
	//{
	//	vec[i].setDigit(i);
	//	cout << vec[i] << ' ';
	//}
	//cout << endl;
	//
	//shuffle(begin(vec), end(vec), g);

	//for (size_t i = 0; i < vec.size(); i++)
	//{
	//	cout << vec[i] << ' ';
	//}
	//cout << endl;

	//sort(begin(vec), end(vec));
	//
	//for (size_t i = 0; i < vec.size(); i++)
	//{
	//	cout << vec[i] << ' ';
	//}
	//cout << endl;

	//Digit pp;
	//cout << ++pp << endl;
	//cout << pp << endl;
	//cout << --pp << endl;
	//cout << pp << endl;
	//cout << pp++ << endl;
	//cout << pp << endl;
	//cout << pp-- << endl;
	//cout << pp << endl;

	DigitVector vec(10);
	cout << vec[0]++ << endl;
	cout << vec[0] << endl;

	return 0;
}