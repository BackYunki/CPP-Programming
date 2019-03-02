#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <string>
using namespace std;

class Fraction
{
private:
	int _numerator;
	int _denominator;

public:
	Fraction(const int& x = 0, const int& y = 1)
	{
		_numerator	 = x;
		_denominator = y;
	}
	~Fraction() {}
	
	void print()
	{
		cout << _numerator << " / " << _denominator << '\n';
	}
};

int main()
{
	Fraction my_fraction0;
	Fraction my_fraction1{ 3.0, 4 };	// cully brakit 은 타입체킹에 더 엄격하다.
	Fraction my_fraction2(3.0, 4);
	my_fraction0.print();
	my_fraction1.print();
	my_fraction2.print();
	return 0;
}