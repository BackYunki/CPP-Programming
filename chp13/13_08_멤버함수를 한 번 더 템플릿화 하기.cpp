#include <iostream>
using namespace std;

template<class T>
class A
{
private:
	T m_value;

public:
	A(const T & in_value) : m_value(in_value) {}

	template<typename TT>
	void doSomething()
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
		cout << (TT)m_value << endl;
	}

	template<typename TT>
	void doSomething2(const TT & input)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
		cout << (TT)m_value << endl;
	}

	void print()
	{
		cout << m_value << endl;
	}
};

int main()
{
	A<char> a_char('A');
	a_char.print();

	a_char.doSomething<int>();	// 인자가 없는 경우에는 타입추론이 불가능한 경우라서 <int> 명시를 해줘야함
	a_char.doSomething2(int());	// 인자가 있으면 안 써줘도 됨!
	return 0;
}