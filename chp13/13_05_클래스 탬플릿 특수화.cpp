#include <iostream>
#include <array>
#include "Storage8.h"

using namespace std;

template<typename T>
class A	// class<T>와 비슷하다리 그치만 그건 문법오류얌
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

template<>	// 부등호 사이에 아무내용이 없으면 특수화 하겠다는 의미, 결국은 다른 클래스가 되어 버린다리.
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
	// C++17에서는 클래스명<타입> 에서 <타입>을 안 넣어도 된다.
	A<int>		a_int(1);
	A<double>	a_double(3.14);
	A<char>		a_char('a');

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();

	a_int.test();
	a_double.test();
	// a_char.test();// 안 뜬다. 문법 상 다른 클래스 구현하는 것임... 인스턴시에이션 할 때 편리하게 하려고 하는 거얌

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