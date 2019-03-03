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
	// static �Լ� �ȿ� non-static ����� �� �� ����.
	// ������ ������ �� ��������� �����̴�.
	// this �� �� ���µ�. this�� Ŭ������ �����ͱ� �����̴�. static �� Ŭ�����κ��� ��� �����Ӵ�.
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
// static ���� �ݵ�� �ʱ�ȭ�� �ʿ��ؼ� �Ʒ����� Ŭ���� �ʱ�ȭ �Լ��� ������ ���� �� �ִ�.
int Something::s_value = 10;
Something::_Init Something::s_initializer;

void print()
{
	cout << "Hello, World!";
}

int main()
{
	// private ���� ���������� �Ұ����ϴ�.
	//cout << Something::s_value << endl;
	// �Լ��� static �̸� ������ ���� ��������� ��ü ���̵� ȣ���� �� �ִ�.
	cout << Something::getValue() << endl;

	Something s1;
	cout << s1.getValue() << endl;


	// �Ϲ� �Լ� �����͸� ������. (����)
	void(*fptr2)() = print;

	// non-static ��� �Լ� �����͸� ������.
	int (Something::*fptr)() = &Something::getValue2;
	cout << (s1.*fptr)() << endl;

	// static ��� �Լ� �����͸� ������.
	// getValue �Լ��� �̸��� Something:: �� �ֱ� ������ ������ ���� �����ϴ� �� ������
	// �� �Լ��� Ŭ������ ���ӵǾ� ���� �ʱ� ������ �Լ������Ϳ� Ŭ���� ���ӽ����̽��� ������ �ʴ´�!
	int (*fptr_s)() = Something::getValue;
	cout << fptr_s() << endl;

	return 0;
}