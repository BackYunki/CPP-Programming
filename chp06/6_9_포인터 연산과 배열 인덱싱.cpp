#include <iostream>

int main()
{
	using namespace std;

	int value = 7;
	int *ptr = &value;
	double value_d = 1.f;
	double *ptr_d = &value_d;
	cout << uintptr_t(ptr) << endl;		//(int)ptr�� ������ ��Ÿ�� ���� �ֵ�. 10������ ������ �ּ� ����ϴ� �Ŷ�� ��
	cout << uintptr_t(ptr_d) << endl;
	cout << sizeof(ptr) << endl;
	cout << sizeof(ptr_d) << endl;
	cout << sizeof(&value) << endl;
	cout << ptr_d << endl;
	cout << ptr_d + 1 << endl;
}