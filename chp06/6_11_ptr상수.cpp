#include <iostream>

int main()
{
	using namespace std;

	//int value = 5;
	//const int *ptr = &value;	// ���� ����Ű�� �ִ� �ּ� �ȿ� �ִ� ���� �� �ٲٰڴٴ� ��
	//value = 6;// �� ������, *ptr = 6; �� �� ��. �ٲ� ���� ������ �� �־ �ڱⰡ �ٲ��� �� ��.

	//int value2 = 6;
	//ptr = &value2;

	//cout << *ptr << endl;

	int value = 5;
	int* const ptr = &value;
	
	*ptr = 10;
	cout << *ptr << endl;

	int value2 = 8;
	//ptr = &value2; �����Ͱ� const ���� �ּҴ� �� �ٲ۴�.


	return 0;
}