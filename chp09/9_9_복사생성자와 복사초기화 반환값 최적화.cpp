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
	Fraction frac(1, 2);	// 릴리즈 모드에서는 복사생성이 뻔히 일어나는 경우도 최적화 해준다.
	cout << &frac << endl;
	return frac;
}

int main()
{
	Fraction frac(3, 5);
	//Fraction fr_copy(frac);

	//cout << frac << '\n' << fr_copy << '\n';
	Fraction test(Fraction(3, 5));	// 컴파일러가 이런 경우는 정말 필요없다고 생각해서 복사 안 하고 생성자 호출한다.
	cout << test << endl;
	
	cout << &doSomething() << endl;
	cout << &doSomething() << endl;	// 연속으로 출력해도 같은 놈으로 인식한다. 주소가 같아!
	
	return 0;
}