#include <iostream>

int main()
{
	using namespace std;

	int value = 7;
	int *ptr = &value;
	double value_d = 1.f;
	double *ptr_d = &value_d;
	cout << uintptr_t(ptr) << endl;		//(int)ptr을 저렇게 나타낼 수도 있데. 10진수로 포인터 주소 출력하는 거라고 함
	cout << uintptr_t(ptr_d) << endl;
	cout << sizeof(ptr) << endl;
	cout << sizeof(ptr_d) << endl;
	cout << sizeof(&value) << endl;
	cout << ptr_d << endl;
	cout << ptr_d + 1 << endl;
}