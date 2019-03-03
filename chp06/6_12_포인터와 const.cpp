#include <iostream>
using namespace std;

int main()
{
	const char* ptr_c = "Hello";
	const int* ptr_i = { 1, 2, 3, 4, 5 };
	const char* ptr_c2 = { 'H', 'e', 'l', 'l', 'o' };

	constexpr int a = 5;
	return 0;
}