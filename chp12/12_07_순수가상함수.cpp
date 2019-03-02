#include <string>
#include <iostream>
using namespace std;

// �߻� Ŭ������ �ϳ� �̻��� �����Լ��� ������ �߻��Լ�����
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
//	cout << "�̰� �����غ��� ȣ���� ���� ����.\n";
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