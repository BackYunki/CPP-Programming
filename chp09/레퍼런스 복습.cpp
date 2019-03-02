#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <tuple>
#include <utility>
using namespace std;

tuple<int, double> getTuple()
{
	int a = 10;
	float f = 3.14f;
	return make_tuple(a, f);
}

struct S
{
	int a, b, c, d;
};

// 호출할 때마다 구조체가 생성되는 건 성능향상을 일으킨다.
S getStruct()
{
	S my_s{ 1, 2, 3, 4 };
	
	return my_s;
}

// 주소 넘기기: 위험해, 함수 끝나고 변수는 사라진다. 메모리 주소로 가도 나중에 쓰레기만 있다.
int* returnByPointer(const int& a, const int& b)
{
	int result = a + b;
	return &result;
}

// delete 어디서 해줄건데? 이런 것도 안 좋아.
int* allocateMemory(const int& size)
{
	return new int[size];
}

int& getValue(const int& x)
{
	int value = x * 2;
	return value;
}

// 해주려면 아래와 같이 확실히 *메모리가 잡혀있는 상태*에서 주소를 주고 받아야함!!!!
int& get(array<int, 100>& my_array, const int& idx)
{
	return my_array[idx];
}

int main()
{
	int* ptr_rbp = returnByPointer(3, 4);
	cout << *ptr_rbp << endl;
	cout << *ptr_rbp << endl;

	//int* array = allocateMemory(10);
	//delete[] array;

	int& value = getValue(5);	// 레퍼런스에 넣고 있어서 얘도 한 번 출력하면 사라진다.
	cout << value << endl;
	cout << value << endl;

	array<int, 100> my_array;
	my_array[30] = 10;
	get(my_array, 30) *= 10;
	cout << get(my_array, 30) << endl;
	
	tuple<int, double> my_tuple = getTuple();
	cout << get<0>(my_tuple) << endl;
	cout << get<1>(my_tuple) << endl;

	auto[int_value, float_value] = getTuple();
	cout << int_value << endl;
	cout << float_value << endl;

	return 0;
}