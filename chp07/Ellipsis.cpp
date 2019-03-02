#include <iostream>
#include <cstdarg>
using namespace std;

void print(int num, ...)
{
	va_list list;
	va_start(list, num);

	for (int i = 0; i < num; ++i)
	{
		cout << va_arg(list, int) << endl;
	}

	va_end(list);
}

int main()
{
	print(3, 1, 2, 3);
	return 0;
}