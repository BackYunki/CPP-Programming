#include <iostream>
#include <cassert>
using namespace std;
/*
	explicit : converting constructer 를 막는다. 꼼꼼하게 코딩할 때 씀.
	delete : 생성자 = delete 하면 해당 생성자를 못 쓰게 한다.
			 주로 버전업 했을 때, 그 기능을 못 쓰게 하려고 씀.
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
	// doSomething(7); <- 생성자에 explicit 을 달아둬서 암묵적 형변환이 안 일어나게 막아뒀다.

	// cout << Fraction('c') << endl; <- delete 키워드로 문자열로 만드는 생성자는 막아버렸다.

	return 0;
}