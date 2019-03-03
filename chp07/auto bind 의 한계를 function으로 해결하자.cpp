#include <iostream>
#include <functional>
/*
	auto 로 bind 의 타입을 알아내는 데는 한계가 있다.
	function<반환타입(인자들)> foo = bind(함수포인터, 인자1, 인자2 또는 placeholders::_1, ... );
*/
using namespace std;

int multiple(const int _a, const int _b)
{
	return _a * _b;
}

int main()
{
	function<int(void)> func1;

	bool select = false;

	while (true)
	{
		cin >> select;
		switch (select)
		{
		case true:
			func1 = bind(multiple, 10, 2);
			break;
		case false:
			func1 = bind(multiple, 20, 3);
			break;
		}

		cout << "값: " << func1() << '\n';
	}

	return 0;
}