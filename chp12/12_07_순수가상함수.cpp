#include <string>
#include <iostream>
using namespace std;

// 추상 클래스는 하나 이상의 가상함수가 있으면 추상함수랑께
class Animal
{
protected:
	string m_name;
public:
	Animal(string name)
		: m_name(name)
	{

	}
public:
	string getName() { return m_name; }
	virtual void speak() const = 0;	// pure virtual function 
	~Animal()
	{
		cout << "Animal dtor\n";
	}
};

//void Animal::speak() const
//{
//	cout << "이건 구현해봤자 호출할 수가 없다.\n";
//}

class Cow : public Animal
{
public:
	Cow(string name) 
		: Animal(name) {}

	virtual void speak() const
	{
		cout << "Umm Moo~\n";
	}

	~Cow()
	{
		cout << "Cow dtor\n";
	}
};

int main()
{
	Cow cow("hellow");
	cow.speak();

	return 0;
}