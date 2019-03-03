#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>
using namespace std;
int cnt = 0;
class Student
{
private:
	string _name;
	int _id;

public:
	// ������ �ڵ�� �� �������� �Ͼ�� ������.
	// �Ʒ��� ���� ��� �̴ϼȶ����� ����Ʈ�� ����Ͽ�
	// ���� �����ڸ� ȣ���ϰ� �� ���� �ִ�.
	Student() : Student("unknown") {}

	Student(const string &name_in)
	{
		init(name_in, cnt++);
	}

	~Student() {}

	// ������ �ڵ�� �и� ���ѳ��� �� ����.
	void init(const string& name_in, const int& id_in)
	{
		_name   = name_in;
		_id		= id_in;
	}

	void print()
	{
		cout << "ID: " << _id << ", Name: " << _name << '\n';
	}
};

int main()
{
	Student person1;
	Student person2("yunki");
	person1.print();
	person2.print();
	return 0;
}