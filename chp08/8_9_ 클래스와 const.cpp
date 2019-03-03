#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>
using namespace std;

class Something
{
private:
	int s_value;

public:
	Something(const Something &origin)
	{
		this->s_value = origin.s_value;
		cout << "���� �����ڰ� ȣ��Ǿ����ϴ�.\n";
	}

	Something(const int& value)
	{
		s_value = value;
		cout << "�����ڰ� ȣ��ƽ��ϴ�.\n";
	}
	
	void setValue(const int& value)
	{
		s_value = value;
	}
	int getValue() const	// ��ü�� const �� �ɰŶ�� ���⿡ ���� �ٲ��� ���� ������ const �� ����������
	{
		return s_value;
	}
};

void print(const Something &s)	// �̷��� ���۷����� �Ѿ�� ���簡 �Ͼ�� �ʴ´�.
//void print(Something s) = > ���� �����ڰ� ȣ��ȴ�.
{
	cout << "�Ѿ�� ������ �ּ�: " << (int)&s << endl;
	cout << s.getValue() << endl;
}

int main()
{
	const Something s1(10);
	//s1.setValue(20);
	cout << s1.getValue() << endl;	// �׷��� ���⼭ �� �� ����
	cout << '\n';

	cout << "�������� ������ �ּ�: " << (int)&s1 << endl;
	print(s1);
	return 0;
}