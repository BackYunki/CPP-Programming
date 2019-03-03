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
	// 생성자 코드는 한 곳에서만 일어나는 게좋다.
	// 아래와 같이 멤버 이니셜라이저 리스트를 사용하여
	// 기존 생성자를 호출하게 할 수도 있다.
	Student() : Student("unknown") {}

	Student(const string &name_in)
	{
		init(name_in, cnt++);
	}

	~Student() {}

	// 생성자 코드는 분리 시켜놓는 게 좋다.
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