#include <iostream>
#include <array>
#include "Storage8.h"

using namespace std;

template<typename T>
class A	// class<T>�� ����ϴٸ� ��ġ�� �װ� ����������
{
public:
	A(const T & input) {}

	void doSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void test()
	{

	}
};

template<>	// �ε�ȣ ���̿� �ƹ������� ������ Ư��ȭ �ϰڴٴ� �ǹ�, �ᱹ�� �ٸ� Ŭ������ �Ǿ� �����ٸ�.
class A<char>
{
public:
	A(const char & temp) {}

	void doSomething()
	{
		cout << "Char type specialization.\n";
	}
};

int main()
{
	// C++17������ Ŭ������<Ÿ��> ���� <Ÿ��>�� �� �־ �ȴ�.
	A<int>		a_int(1);
	A<double>	a_double(3.14);
	A<char>		a_char('a');

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();

	a_int.test();
	a_double.test();
	// a_char.test();// �� ���. ���� �� �ٸ� Ŭ���� �����ϴ� ����... �ν��Ͻÿ��̼� �� �� ���ϰ� �Ϸ��� �ϴ� �ž�

	Storage8<int> intStorage;

	for (int count = 0; count < 8; count++)
		intStorage.set(count, count);

	for (int count = 0; count < 8; count++)
		cout << intStorage.get(count) << '\n';

	cout << "Sizeof Storage8<int> " << sizeof(Storage8<int>) << '\n';

	Storage8<bool> boolStorage;
	for (int count = 0; count < 8; count++)
		boolStorage.set(count, true);

	for (int count = 0; count < 8; count++)
		cout << boolStorage.get(count) << '\n';

	cout << "Sizeof Storage8<bool> " << sizeof(Storage8<bool>) << '\n';

	return 0;
}