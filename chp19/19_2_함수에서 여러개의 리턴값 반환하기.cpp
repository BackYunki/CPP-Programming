#include <iostream>
#include <tuple>
using namespace std;

//tuple<int, int> my_func()
//{
//	return tuple<int, int>(123, 456);
//}

auto my_func()
{
	return tuple<int, int, int>(123, 456, 789);
}

auto my_func_cpp17()
{
	return tuple(123, 456, 789, 10);
}

int main()
{
	/*tuple<int, int> result = my_func();*/
	// 14 버전까진 이렇게
	auto result = my_func();
	cout << get<0>(result) << " " << get<1>(result) << " " << get<2>(result) << endl;

	// 17 버전
	auto [a,b,c,d] = my_func_cpp17();
	cout << a << ", " << b << ", " << c << ", " << d << "\n";
	return 0;
}