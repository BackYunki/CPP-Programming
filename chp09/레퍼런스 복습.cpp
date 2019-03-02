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

// ȣ���� ������ ����ü�� �����Ǵ� �� ��������� ����Ų��.
S getStruct()
{
	S my_s{ 1, 2, 3, 4 };
	
	return my_s;
}

// �ּ� �ѱ��: ������, �Լ� ������ ������ �������. �޸� �ּҷ� ���� ���߿� �����⸸ �ִ�.
int* returnByPointer(const int& a, const int& b)
{
	int result = a + b;
	return &result;
}

// delete ��� ���ٰǵ�? �̷� �͵� �� ����.
int* allocateMemory(const int& size)
{
	return new int[size];
}

int& getValue(const int& x)
{
	int value = x * 2;
	return value;
}

// ���ַ��� �Ʒ��� ���� Ȯ���� *�޸𸮰� �����ִ� ����*���� �ּҸ� �ְ� �޾ƾ���!!!!
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

	int& value = getValue(5);	// ���۷����� �ְ� �־ �굵 �� �� ����ϸ� �������.
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