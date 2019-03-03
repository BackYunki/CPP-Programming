#include <iostream>
#include <Windows.h>
using namespace std;

void countDown(int count)
{
	if (count == 0) return;
	cout << count << endl;
	//Sleep(1000);
	countDown(--count);
}

int sumTo(int sumto)
{
	if (sumto <= 0) return 0;

	else
	{
		return sumTo(sumto - 1) + sumto;
	}
}

int fib(int n)
{
	if (n == 0 || n == 1) return n;
	else return fib(n - 1) + fib(n - 2);
}

int main()
{
	//countDown(5);
	cout << sumTo(10) << endl;
	
	for (size_t i = 0; i <= 10; i++)
	{
		cout << i + 1 << "Ç×: " << fib(i) << endl;
	}
	return 0;
}