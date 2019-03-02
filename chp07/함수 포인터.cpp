#include <iostream>
#include <array>
#include <functional>

using namespace std;

int func(int x)
{
	return x;
}

int goo()
{
	return 10;
}

bool isEven(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;
}

bool isOdd(const int& number)
{
	if (number % 2 == 1) return true;
	else return false;
}

// 별명으로 쓰는 법 두 가지
// typedef bool(*check_func_t)(const int&);
// void printNumbers(const array<int, 10> &my_array, check_func_t check_func = isEven)

// using check_func_t = bool(*)(const int&);
// void printNumbers(const array<int, 10> &my_array, check_func_t check_func = isEven)
void printNumbers(const array<int, 10> &my_array, function<bool(const int&)> check_func = isEven)
//void printNumbers(const array<int, 10> &my_array, bool (*check_func)(const int&) = isEven)
{
	for (auto element : my_array)
	{
		if (check_func(element) == true) cout << element << ' ';
	}
	cout << endl;
}

int main()
{
	// func();	// 함수도 사실은 포인터다. 복귀 주소를 저장하고 함수의 주소로 다녀온다.
	//cout << func << endl;

	/*int (*func_ptr)(int) = func;
	
	cout << func_ptr(5) << endl;

	func_ptr = goo;

	cout << func_ptr() << endl;*/

	array<int, 10> my_array{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	function<bool(const int&)> fncptr = isEven;
	printNumbers(my_array, fncptr);
	printNumbers(my_array);	// 함수 포인터도 
	printNumbers(my_array, isEven);
	printNumbers(my_array, isOdd);

	return 0;
}