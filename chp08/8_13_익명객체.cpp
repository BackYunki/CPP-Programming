#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>
using namespace std;


// 변수명이 없어서 오직 한 번만 사용할 수 있고 사라져버린다.
// 
class A
{
public:
	int m_value;

	A(const int& input) : m_value(input)
	{
		cout << "Constructor\n";
	}
	~A()
	{
		cout << "Destructor\n";
	}
	void printDouble()
	{
		cout << m_value * 2 << endl;
	}
};

class Cents
{
private:
	int m_cents;
public:
	Cents(const int& cents) { m_cents = cents; }

	int getCents() const { return m_cents; }	// 아래 add 함수가 상수 객체를 받는다
};

Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

int main()
{
	A a(1);
	a.printDouble(); //-> 프린트 외에 별다른 기능을 쓰지 않는다면, 그냥 익명객체로 만들어 출력하자.
	
	A(1).printDouble();
	A(1).printDouble();	// 익명객체는 그 때 그 때 만들어진다리

	cout << add(Cents(6), Cents(8)).getCents() << endl;
	cout << int(6) + int(8) << endl;

	return 0;
}