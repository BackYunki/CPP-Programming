#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;
int main()
{
	int fibonacci[] = { 0 , 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

	for (int number : fibonacci)
		cout << number << ' ';
	cout << endl;

	for (auto& number : fibonacci)	// 참조로 하면 값을 바꿀 수 있다리
	{
		number *= 10;
		cout << number << ' ';
	}
	cout << endl;

	int max_number = numeric_limits<int>::lowest();
	for (const auto &n : fibonacci)
	{
		max_number = max(max_number, n);
	}
	cout << max_number << endl;
}