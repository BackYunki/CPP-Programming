#include <iostream>
#include <functional>
/*
	auto �� bind �� Ÿ���� �˾Ƴ��� ���� �Ѱ谡 �ִ�.
	function<��ȯŸ��(���ڵ�)> foo = bind(�Լ�������, ����1, ����2 �Ǵ� placeholders::_1, ... );
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

		cout << "��: " << func1() << '\n';
	}

	return 0;
}