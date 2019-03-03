#include <iostream>

int main()
{
	using namespace std;

	int arr[5] = { 1, 2, 3, 4, 5 };
	cout << sizeof(arr) << endl;

	int *ptr = arr;

	cout << sizeof(ptr) << endl;
	double d = 5.f;
	double *ptr_d = &d;
	
	cout << sizeof(ptr_d) << endl;	// 포인터의 크기는 32비트 os: 4바이트, 64비트는 8바이트다.
	return 0;
}