#include <iostream>
#include <vector>
#include <functional>
#include <array>
#include <tuple>
using namespace std;

// 매번 복사가 되는 방식이라 안 좋다.
int getValue(const int x)
{
	int value = x * 2;
	return value;
}

// 함수 내 로컬 변수의 포인터를 보내서. 함수 실행하고 얼마 안 있다가 사라지므로 주소 받는 건 위험해!
int* getValueWithPointer(const int x)
{
	int value = x * 2;
	return &value;
}

// 이건 뉴는 여기서 하고 딜리트는 어디서 해야할지 막막할 수 있어서 안 좋다!
int* allocateMemory(int size)
{
	return new int[size];
}

// Return by reference : 내가 정말 잘 이해 못 하는 거당....
// 이것도 로컬 변수가 사라져서 리턴 값 받고 난 이후에 또 쓰면 쓰레기값이 나온다.
int& getValueByReference(const int &x)
{
	int value = x * 2;

	return value;
}

int& get(array<int, 100>& my_array, int idx)
{
	return my_array[idx];
}

std::tuple<int, double> getTuple()
{
	int a = 10;
	int d = 3.14;
	return std::make_tuple(a, d);
}

int main()
{
	int value = getValue(3);	// 복사가 오질나게 일어난다.
	
	// 로컬 주소를 받아오면 함수 실행 후 사라진다.
	int* valueWithPointer = getValueWithPointer(3);
	cout << *valueWithPointer << endl;
	cout << *valueWithPointer << endl;
	
	int* array = new int[10];
	// int* array = allocateMemory(10);
	
	delete[] array;

	// 얘도 지역변수를 리턴해서 위험해
	int& refValue = getValueByReference(3);
	cout << refValue << endl;
	cout << refValue << endl;

	std::array<int, 100> my_array;
	my_array[30] = 10;
	get(my_array, 30) = 1024;
	cout << my_array[30] << endl;

	/*
	std::tuple<int, double> my_tuple = getTuple();
	cout << get<0>(my_tuple) << endl;
	cout << get<1>(my_tuple) << endl;
	*/
	auto[a, d] = getTuple();
	cout << a << endl;
	cout << d << endl;
	return 0;
}