#include <iostream>
#include <cassert>
using namespace std;
/*
	explicit : converting constructer �� ���´�. �Ĳ��ϰ� �ڵ��� �� ��.
	delete : ������ = delete �ϸ� �ش� �����ڸ� �� ���� �Ѵ�.
			 �ַ� ������ ���� ��, �� ����� �� ���� �Ϸ��� ��.
*/
class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	
	Fraction(char c) = delete;
	
	explicit Fraction(int num = 0, int den = 1) 
		: m_numerator(num), m_denominator(den)
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

void doSomething(Fraction frac)
{
	cout << frac << endl;
}

int main()
{
	Fraction frac(7);
	// doSomething(7); <- �����ڿ� explicit �� �޾Ƶּ� �Ϲ��� ����ȯ�� �� �Ͼ�� ���Ƶ״�.

	// cout << Fraction('c') << endl; <- delete Ű����� ���ڿ��� ����� �����ڴ� ���ƹ��ȴ�.

	return 0;
}