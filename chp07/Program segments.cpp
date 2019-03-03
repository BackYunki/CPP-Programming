#include <iostream>
using namespace std;

int g_int0;
const int g_int = 1;
static int static_int;

int foo(int var)
{
	static const int temp = 1;

	return temp + var;
}

int main()
{
	int var = foo(0);
	int arr[] = { 1,2,3 };
	arr[4] = 5;
	cout << arr[4];
	cout << var << endl;

	int* integer = new int(0);

	delete integer;

	return 0;
}