#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>
using namespace std;


// �������� ��� ���� �� ���� ����� �� �ְ� �����������.
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

	int getCents() const { return m_cents; }	// �Ʒ� add �Լ��� ��� ��ü�� �޴´�
};

Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

int main()
{
	A a(1);
	a.printDouble(); //-> ����Ʈ �ܿ� ���ٸ� ����� ���� �ʴ´ٸ�, �׳� �͸�ü�� ����� �������.
	
	A(1).printDouble();
	A(1).printDouble();	// �͸�ü�� �� �� �� �� ��������ٸ�

	cout << add(Cents(6), Cents(8)).getCents() << endl;
	cout << int(6) + int(8) << endl;

	return 0;
}