#include <iostream>
#include <vector>
#include <functional>
#include <array>
#include <tuple>
using namespace std;

// �Ź� ���簡 �Ǵ� ����̶� �� ����.
int getValue(const int x)
{
	int value = x * 2;
	return value;
}

// �Լ� �� ���� ������ �����͸� ������. �Լ� �����ϰ� �� �� �ִٰ� ������Ƿ� �ּ� �޴� �� ������!
int* getValueWithPointer(const int x)
{
	int value = x * 2;
	return &value;
}

// �̰� ���� ���⼭ �ϰ� ����Ʈ�� ��� �ؾ����� ������ �� �־ �� ����!
int* allocateMemory(int size)
{
	return new int[size];
}

// Return by reference : ���� ���� �� ���� �� �ϴ� �Ŵ�....
// �̰͵� ���� ������ ������� ���� �� �ް� �� ���Ŀ� �� ���� �����Ⱚ�� ���´�.
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
	int value = getValue(3);	// ���簡 �������� �Ͼ��.
	
	// ���� �ּҸ� �޾ƿ��� �Լ� ���� �� �������.
	int* valueWithPointer = getValueWithPointer(3);
	cout << *valueWithPointer << endl;
	cout << *valueWithPointer << endl;
	
	int* array = new int[10];
	// int* array = allocateMemory(10);
	
	delete[] array;

	// �굵 ���������� �����ؼ� ������
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