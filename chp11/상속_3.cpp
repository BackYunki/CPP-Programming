#include <iostream>
using namespace std;

class Mother
{
private:
	int m_i;
protected:
	int m_prot;
public:
	int m_pub;

	Mother() {}
	Mother(const int & i) : m_i(i), m_prot(i)
	{
		cout << "Mother construction\n";
	}
	~Mother()
	{
		cout << "Mother destruction\n";
	}
};

class Child : private Mother
{
private:
	double m_d;
public:
	Child() : Mother(1024), m_d(1.0) // il���� ������ ������ �ٲ㵵 �����Ϸ��� �θ�Ŭ���� ���� �ʱ�ȭ�Ѵ�.
	{
		cout << Mother:: << endl;
		cout << "Child construction\n";
	}
	~Child()
	{
		cout << "Child destruction\n";
	}
};

int main()
{
	Child c1;

	cout << sizeof(Child) << '\n';	// ����� �������� ũ�� �����µ�. ����Ŭ������ ����� ���� �� �ְ� �Ϸ��� �ϴ� ���̴�.
	cout << sizeof(Mother) << '\n';
	
	return 0;
}