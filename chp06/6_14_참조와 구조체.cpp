#include <iostream>
using namespace std;

struct Person
{
	int age;
	double weight;
};

int main()
{
	Person person;

	person.age = 5;
	person.weight = 30;

	cout << person.age << " " << person.weight << endl;

	Person &ref = person;
	ref.age = 10;
	ref.weight = 40;

	cout << person.age << " " << person.weight << endl;

	Person *ptr = &person;	// 포인터를 구조체에 쓸 때는 멤버참조로 .을 쓰지 않고 화살표를 쓰자고 약속했음.
	ptr->age = 15;
	ptr->weight = 50;

	cout << person.age << " " << person.weight << endl;

	(*ptr).age = 20;
	(*ptr).weight = 60;

	cout << person.age << " " << person.weight << endl;

	Person &ref2 = *ptr;
	ref2.age = 25;
	ref2.weight = 70;

	cout << person.age << " " << person.weight << endl;

	return 0;
}