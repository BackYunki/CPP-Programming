#include <iostream>
#include <array>
#include <functional>

using namespace std;

bool isEven(const int& element)
{
	if (element % 2 == 0)	return true;
	else					return false;
}
bool isOdd(const int& element)
{
	if (element % 2 == 1)	return true;
	else					return false;
}

// �Լ� �����͵� �⺻���� ���� �� �ִ�. ���⼭ �⺻���� �Լ��� �ǰ���?
// bool(*foo)(...) = var;

// �Լ������Ͱ� �ʹ� ��ٽ����� ������ ����
// 1. typedef bool(*check_mode_t)(const int&); => ���߿��� check_mode_t check_mode = foo; �� �����ϸ� ��.
// 2. using check_mode_t = bool(*)(const int&);  => 2���� �� �� ��� �� �� ���ٸ�
// �� ���� �� �ִµ�. �װ� �ٷ� function<> �̴�!!!
void printModeWith(bool(*check_mode)(const int&), const array<int, 10> &my_array)
{
	for (auto element : my_array)
		if (check_mode(element)) cout << element << ' ';
	
	cout << '\n';
}

void printModeWith(function<bool(const int& element)> check_mode, const array<int, 10> &my_array)
{
	for (auto element : my_array)
		if (check_mode(element)) cout << element << ' ';

	cout << '\n';
}

int main()
{
	array<int, 10> my_array{ 1,2,3,4,5,6,7,8,9,10 };
	
	function<bool(const int& element)> mode_func;

	printModeWith(isOdd, my_array);
	printModeWith(isEven, my_array);

	printModeWith(mode_func, my_array);
	//mode_func = isEven;
	mode_func = bind(isEven, placeholders::_1);
	printModeWith(mode_func, my_array);
	
	return 0;
}