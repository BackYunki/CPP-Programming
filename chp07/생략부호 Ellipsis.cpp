#include <iostream>
#include <cstdarg>	// for Ellipsis
using namespace std;

double findAverage(int count, ...)
{
	double sum = 0;

	va_list list;

	va_start(list, count);

	for (int avg = 0; avg < count; ++avg)
	{
		sum += va_arg(list, int);
	}

	va_end(list);

	return sum / count;
}

int getMult(int count, ...)
{
	va_list list;

	va_start(list, count);
	int sum = 1;
	while (count--)
	{
		int element = va_arg(list, int);
		sum *= element;
	}
	va_end(list);
	return sum;
}

int main()
{
	cout << findAverage(3, 1, 2, 3) << endl;
	
	cout << getMult(3, 1, 5, 10) << endl;
	return 0;
}