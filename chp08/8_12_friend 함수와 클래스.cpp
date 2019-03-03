#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>
using namespace std;
/*
	연산자 오버로딩에서 프렌드를 많이 쓴다.
	접근하고 싶은 클래스 밖에서 멤버변수에 접근하기 위한 권한을 주는 용도로 쓴다.
	클래스 내에서 friend 를 붙여서 프로토 타입을 만들고 밖에서 그 함수를 정의하면 된다.
*/

class A;

class B
{
private:
	int m_value = 2;

public:
	void doSomething(A& a);
	//{ cout << a.m_value << endl; } <- 여기선 A를 알아도 멤버변수는 알 수 없다.
	// 그래서 여기선 프로토타입만 만들고 아래에서 정의해주면 된다.
	// 이걸 선언과 정의의 분리라고 한다.
};

class A
{
private:
	int m_value = 1;

	//friend class B; <- 통째로 열어주는 건 좀 부담스럽다.
	friend void B::doSomething(A& a);
};

void B::doSomething(A& a)
{
	cout << a.m_value << endl;
}

int main()
{
	A a;
	B b;
	b.doSomething(a);

	return 0;
}