#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <chrono>
using namespace std;

void func1()
{
	long long sum = 0;
	for (unsigned i = 0; i < 1000'000; ++i)
	{
		sum += i;;
	}

	cout << sum << '\n';
}

void func2()
{
	unsigned long long sum = 0;

	sum = 500'000'000ULL * 999'999'999ULL;

	/*for (unsigned i = 0; i < 1'000'000'000; i++)
	{
		sum += i;
	}*/

	cout << sum << '\n';
}

void run()
{	
	func1();
	func2();
}

/*
	�޸� �������ϸ��� CPU�������ϸ��� ���� �ϸ� ��Ȯ���� ������ �� ������,
	�Ϲ����� ���� ���ÿ� �ص� ū ���̰� ���ٰ� �Ѵ�.
*/
int main()
{

	run();

	int* d = new int[10000];
	float* f = new float[100];

	delete[] d;
	delete[] f;

	return 0;
}