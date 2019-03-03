#include <iostream>
#include <typeinfo> // typeid(&T).name() 쓰려고

struct YUNKI
{
	const char* name;
};

int main()
{
	// 포인터는 (자료형)의 '주소'를 저장하는 '변수' 다.
	// int는 '정수'를 저장하는 '변수'

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