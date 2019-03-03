#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// 컴마 연산자도 있다.
	int a = 1, b = 10;
	int c = (a++, a + b);
	std::cout << c << std::endl << std::endl;

	bool onSale = true;

	const int price = (onSale ? 10 : 100);
	std::cout << price << std::endl << std::endl;

	int x = 5;

	std::cout << ((x%2 == 0) ? "even" : "odd") << std::endl;

	double d1(100 - 99.99);
	double d2(10 - 9.99);
	
	const double epsilon = 1e-14;

	if (abs(d1 - d2) < epsilon)
	{
		cout << "Approximately Equal\n";
	}
	else
	{
		cout << "Not Equal\n";
	}

	cout << '\n';

	int x2 = 10;
	int y2 = 11;

	if (x2++ == y2 && y2++ == 12)
	{
		// do something
	}
	cout << y2 << endl;	// y가 12가 못 되고 11이 된 이유는 && 연산에서 좌측이 거짓이면 우측은 계산을 안 하기 때문임

	cout << '\n';

	return 0;
}
//1 의 2의 보수는?
//01 + () = 10
//01 + 01 = 10