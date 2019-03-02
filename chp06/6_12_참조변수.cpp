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

	//int& ref = value;	// value 가 잡고 있는 메모리를 같이 가리킴
	//cout << ref << endl;
	//cout << value << endl;
	//ref = 10;
	//cout << ref << endl;
	//cout << value << endl << endl;

	//cout << &value << endl;
	//cout << &ref << endl;
	//cout << ptr << endl;
	//cout << &ptr << endl;	// reference는 변수의 다른 이름인 것이군! = 별명 => 원래 이름이 꼭 있어야함 = 초기화가 되어야 한다.

	//const int y = 8;
	////int& ref = y;	reference 가 y를 마음대로 바꿔버릴 수도 있어서 이 경우엔 const로 선언해야 함
	//const int& ref = y;

	//int a = 10;
	//int* p_a = &a;

	//cout << &p_a << endl;	// 포인터도 주소값이 복사가 되는 거지 포인터 자체가 넘겨지는 건 아님.
	//test(p_a);				// 함수 안에 있는 새로운 포인터에 주소값만 넘어가는 거다. 아예 다른 놈이야.

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


