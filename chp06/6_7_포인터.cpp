#include <iostream>
#include <typeinfo> // typeid(&T).name() ������

struct YUNKI
{
	const char* name;
};

int main()
{
	// �����ʹ� (�ڷ���)�� '�ּ�'�� �����ϴ� '����' ��.
	// int�� '����'�� �����ϴ� '����'

	using namespace std;

	int x = 5;
	cout << x << endl;
	cout << &x << endl;
	cout << (int)&x << endl;
	cout << *(&x) << endl;
	cout << typeid(&x).name() << endl;
	cout << typeid(YUNKI).name() << endl;

	return 0;
}