#include <iostream>
#include <string>
#include <vector>
#include <utility>

struct Person
{
	std::string name = "Unknown";
	int age = 20;

	void print()
	{
		std::cout << name << ": " << age << std::endl;
	}

	bool operator==(const Person& lhs)
	{
		return (lhs.name == name && lhs.age == age) ? true : false;
	}
};

int main()
{
	using namespace std;

	Person me	{ "¹éÀ±±â",25 };
	Person me2	{ "¹éÀ±±â",25 };

	me.print();
	cout << boolalpha << (me == me2) << endl;

	Person guest;
	guest.print();

	return 0;
}