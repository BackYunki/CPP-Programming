#include "MyArray.h"
// #include "MyArray.cpp" <- ���߿� ������Ʈ�� Ŀ���� ������ �����. �̹����� �� ����¸��� �����
using namespace std;

int main()
{
	// <> �ȿ��� ������ Ÿ�ӿ� �˷��� ���鸸 �� �� �ִ�. ���� �� ��!!
	MyArray<double, 100> my_array;

	for (unsigned int i = 0; i < my_array.getLength(); i++)
	{
		my_array[i] = i * 10;
	}

	my_array.print();

	return 0;
}