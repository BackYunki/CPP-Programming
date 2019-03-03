#include <iostream>
#include <functional>

using namespace std;

class Arithmetic
{
public:
	Arithmetic() {}
	~Arithmetic() {}

	int getPlus(const int &x, const int &y)
	{
		return x + y;
	}
	int getMinus(const int &x, const int &y)
	{
		return x - y;
	}
	int getMultiply(const int &x, const int &y)
	{
		return x * y;
	}
	double getDivide(const double &x, const double &y)
	{
		if (y == 0)
		{
			cout << "NaN\n";
			return -1;
		}
		else
		{
			return x / y;
		}
	}
};

int getMultiply(const int &x, const int &y)
{
	return x * y;
}

int main()
{
	Arithmetic calc;
	int(*func_ptr1)(const int&, const int&);
	func_ptr1 = getMultiply;
	cout << func_ptr1(3, 5) << endl;

	auto func_ptr2 = bind(getMultiply, 10, 20);
	cout << func_ptr2() << endl;

	auto func_ptr3 = bind(getMultiply, placeholders::_1, placeholders::_2);
	cout << func_ptr3(0, 20) << endl;

	auto class_func1 = bind(&Arithmetic::getMultiply, calc, placeholders::_1, placeholders::_2);
	cout << class_func1(1, 3) << endl;

	function<double(const double&, const double&)> functor = bind(&Arithmetic::getMultiply, calc, placeholders::_1, placeholders::_2);

	cout << functor(3, 5) << endl;

	return 0;
}