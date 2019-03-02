#include <iostream>

template <typename T, typename U>
auto add(const T& a, const U& b)
{
	return a + b;
}

auto add(int x, int y) -> int	// trailing auto : auto 의 타입명시
{
	return x + y;
}

int main()
{
	using namespace std;

	auto a = 123;
	auto d = 123.0;
	auto c = 1 + 2.0;

	cout << "a: " << a << endl;
	cout << "d: " << d << endl;
	cout << "c: " << c << endl;

	auto result = add(3, 4);
	cout << "result : " << result << endl;

	auto template_result = add(3.0, 4);
	cout << template_result << endl;
	return 0;
}