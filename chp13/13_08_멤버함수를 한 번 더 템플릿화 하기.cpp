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

	a_char.doSomething<int>();	// ���ڰ� ���� ��쿡�� Ÿ���߷��� �Ұ����� ���� <int> ��ø� �������
	a_char.doSomething2(int());	// ���ڰ� ������ �� ���൵ ��!
	return 0;
}