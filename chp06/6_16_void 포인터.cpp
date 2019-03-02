#include <iostream>
using namespace std;

// void pointer = generic pointer ��� ��.

enum Type
{
	INT,
	CHAR,
	FLOAT,
	DOUBLE,
};

int main()
{
	int		i = 5;
	float	f = 3.0f;
	char	c = 'a';

	void *ptr = nullptr;

	ptr = &i;
	ptr = &f;
	//ptr = &c;

	Type ptrType = FLOAT;

	// cout << ptr + 1 << endl;	// void�̸� �� ����Ʈ�� ���ؾ����� �� �� ����. int �� 4ĭ ���ٵ�. void�� ���ݾ�!
	// cout << *ptr << endl;	// � Ÿ������ �� �� ��� �������� �� �ȴ�. ������ ǥ���� �ɷ� ��������, �÷�Ʈ���� �� �� ���ݾ�!
	cout << *static_cast<float*>(ptr) << endl;	// ���� ����ȯ�� �ؾ� �������� �ȴ�.
	// ���������� void �����͸� ����� ���� ���� ������. �ּ��� Ư¡�� �����ϴ� ���� ������ �ȴٸ�

	// ���� ���ٸ� �Ʒ��� ���� ��
	if (ptrType == FLOAT)
	{
		cout << *static_cast<float*>(ptr) << endl;
	}
	else if (ptrType == INT)
	{
		cout << *static_cast<int*>(ptr) << endl;
	}
	else if (ptrType == CHAR)
	{
		cout << *static_cast<char*>(ptr) << endl;
	}
	else
	{
		cout << *static_cast<double*>(ptr) << endl;
	}
	return 0;
}