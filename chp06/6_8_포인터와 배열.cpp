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
	
	cout << sizeof(ptr_d) << endl;	// �������� ũ��� 32��Ʈ os: 4����Ʈ, 64��Ʈ�� 8����Ʈ��.
	return 0;
}