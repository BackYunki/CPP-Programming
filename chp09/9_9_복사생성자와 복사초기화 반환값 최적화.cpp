#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int num = 0, int den = 1) : m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
	}

	Fraction(const Fraction& origin) : 
		m_numerator(origin.m_numerator), m_denominator(origin.m_denominator)
	{
		cout << "Copy Constructor Called.\n";
	}

	friend ostream& operator << (ostream& out, const Fraction& rhs)
	{
		out << rhs.m_numerator << " / " << rhs.m_denominator;
		return out;
	}
};

Fraction doSomething()
{
	Fraction frac(1, 2);	// ������ ��忡���� ��������� ���� �Ͼ�� ��쵵 ����ȭ ���ش�.
	cout << &frac << endl;
	return frac;
}

int main()
{
	Fraction frac(3, 5);
	//Fraction fr_copy(frac);

	//cout << frac << '\n' << fr_copy << '\n';
	Fraction test(Fraction(3, 5));	// �����Ϸ��� �̷� ���� ���� �ʿ���ٰ� �����ؼ� ���� �� �ϰ� ������ ȣ���Ѵ�.
	cout << test << endl;
	
	cout << &doSomething() << endl;
	cout << &doSomething() << endl;	// �������� ����ص� ���� ������ �ν��Ѵ�. �ּҰ� ����!
	
	return 0;
}