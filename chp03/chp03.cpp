#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// �ĸ� �����ڵ� �ִ�.
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
	cout << y2 << endl;	// y�� 12�� �� �ǰ� 11�� �� ������ && ���꿡�� ������ �����̸� ������ ����� �� �ϱ� ������

	cout << '\n';

	return 0;
}
//1 �� 2�� ������?
//01 + () = 10
//01 + 01 = 10