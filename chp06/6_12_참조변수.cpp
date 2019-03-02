#include <iostream>
using namespace std;

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};

void test(int* ptr)
{
	cout << &ptr << endl;
}

void printArray(int (&arr)[5])
{
	for (size_t i = 0; i < 5; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main()
{

	//int value = 5;

	//int *ptr = nullptr;
	//ptr = &value;

	//int& ref = value;	// value �� ��� �ִ� �޸𸮸� ���� ����Ŵ
	//cout << ref << endl;
	//cout << value << endl;
	//ref = 10;
	//cout << ref << endl;
	//cout << value << endl << endl;

	//cout << &value << endl;
	//cout << &ref << endl;
	//cout << ptr << endl;
	//cout << &ptr << endl;	// reference�� ������ �ٸ� �̸��� ���̱�! = ���� => ���� �̸��� �� �־���� = �ʱ�ȭ�� �Ǿ�� �Ѵ�.

	//const int y = 8;
	////int& ref = y;	reference �� y�� ������� �ٲ���� ���� �־ �� ��쿣 const�� �����ؾ� ��
	//const int& ref = y;

	//int a = 10;
	//int* p_a = &a;

	//cout << &p_a << endl;	// �����͵� �ּҰ��� ���簡 �Ǵ� ���� ������ ��ü�� �Ѱ����� �� �ƴ�.
	//test(p_a);				// �Լ� �ȿ� �ִ� ���ο� �����Ϳ� �ּҰ��� �Ѿ�� �Ŵ�. �ƿ� �ٸ� ���̾�.

	const int size = 5;
	int arr[size] = { 1, 2, 3, 4, 5 };

	printArray(arr);

	Other ot;

	int &v1 = ot.st.v1;
	v1 = 1;

	int value = 5;
	int* const ptr = &value;
	*ptr = 10;
	cout << value << endl;
	cout << *ptr << endl;
	int& ref = value;
	ref = 20;
	cout << value << endl;
	cout << *ptr << endl;
	cout << ref << endl;

	return 0;
}


