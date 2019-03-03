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

// 함수 포인터도 기본값을 넣을 수 있다. 여기서 기본값은 함수가 되겠지?
// bool(*foo)(...) = var;

// 함수포인터가 너무 길다싶으면 별명을 주자
// 1. typedef bool(*check_mode_t)(const int&); => 나중에는 check_mode_t check_mode = foo; 로 선언하면 됨.
// 2. using check_mode_t = bool(*)(const int&);  => 2번이 좀 더 깔끔 한 것 같다리
// 더 편한 게 있는데. 그게 바로 function<> 이당!!!
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