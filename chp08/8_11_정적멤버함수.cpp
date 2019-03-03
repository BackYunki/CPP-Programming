#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>
using namespace std;

class Something
{
public:
	class _Init
	{
	public:
		_Init()
		{
			s_value = 1234;
		}
	};

private:
	static int s_value;
	static _Init s_initializer;
	int m_value;
	
public:
	// static 함수 안에 non-static 멤버가 올 수 없다.
	// 컴파일 시점에 안 만들어지기 때문이다.
	// this 도 못 쓰는데. this는 클래스의 포인터기 때문이다. static 은 클래스로부터 사실 자유롭다.
	static int getValue()
	{
		//m_value = 10;
		return s_value;
	}

	int getValue2()
	{
		return s_value;
	}
};
// static 들은 반드시 초기화가 필요해서 아래에서 클래스 초기화 함수를 억지로 만들 수 있다.
int Something::s_value = 10;
Something::_Init Something::s_initializer;

void print()
{
	cout << "Hello, World!";
}

int main()
{
	// private 여서 직접접근은 불가능하다.
	//cout << Something::s_value << endl;
	// 함수가 static 이면 컴파일 전에 만들어져서 객체 없이도 호출할 수 있다.
	cout << Something::getValue() << endl;

	Something s1;
	cout << s1.getValue() << endl;


	// 일반 함수 포인터를 만들어보자. (복습)
	void(*fptr2)() = print;

	// non-static 멤버 함수 포인터를 만들어보자.
	int (Something::*fptr)() = &Something::getValue2;
	cout << (s1.*fptr)() << endl;

	// static 멤버 함수 포인터를 만들어보자.
	// getValue 함수의 이름은 Something:: 에 있기 때문에 우측과 같이 접근하는 게 맞지만
	// 이 함수는 클래스에 종속되어 있지 않기 때문에 함수포인터에 클래스 네임스페이스를 붙이지 않는다!
	int (*fptr_s)() = Something::getValue;
	cout << fptr_s() << endl;

	return 0;
}