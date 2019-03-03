#include <iostream>
using namespace std;

int g_a = 123;

void doSomething()
{
	static int a = 0;	// 전역변수는 고정된 주소를 갖고 선언시 반드시 초기화를 해야한다.
	++a;				// 한 번 초기화 해주면 여러번 실행되도 초기화 문장은 무시된다.
	cout << a << endl;	// 이 a는 스코프 때문에 외부에서 접근하려면 포인터가 필요하다.
}

int main()
{
	int a = 1;

	cout << a << endl;
	cout << ::g_a << " " << g_a << endl;	// ::는 전역멤버 접근용이다.

	doSomething();
	doSomething();
	doSomething();
	doSomething();
	return 0;
}