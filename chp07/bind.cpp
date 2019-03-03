#include <iostream>
#include <functional>

using namespace std;

int multiple(int _a, int _b)
{
	return _a * _b;
}

int multiple3and4()
{
	return multiple(3, 4);
}

int multiple5and3()
{
	return multiple(5, 3);
}

int main()
{
	auto _func1 = bind(multiple, 3, 4);
	auto _func2 = bind(multiple, 5, 3);

	cout << "기존방식 : " << multiple3and4() << ',' << multiple5and3() << '\n';
	cout << "bind 사용: " << _func1() << ',' << _func2() << '\n';

	int a = 10;
	int b = 20;
	auto _func3 = bind(multiple, cref(a), cref(b));
	cout << "값 : " << _func3() << '\n';
	a = 20;
	b = 30;
	cout << "값 : " << _func3() << '\n';

	auto _func4 = bind(multiple, 10, placeholders::_1);
	cout << _func4(2) << '\n';

	return 0;
}