#include <iostream>
using namespace std;
/*
�Ǽ��� ���̱� ���� override �ϰڴٰ� ����δ� ����. ���ڰ� �޶� �������̵� �� �� ���� ������ ����
*/
class A
{
public:
	//�������̵� �� �ϰ� final �� �� �� �ִ�.
	//virtual void print() final { cout << "A\n"; }
	void print() { cout << "A\n"; }
	virtual A* getThis() 
	{
		cout << "A::getThis()\n";
		return this; 
	}
};

class B : public A
{
public:
	// ���Ⱑ A�� print�� override �ϰڴٰ� ����� �κ�
	// void print(int x) const override { cout << "B\n"; }
	// virtual void print() final { cout << "B\n"; }
	void print() { cout << "B\n"; }
	virtual B* getThis() 
	{ 
		cout << "B::getThis()\n";
		return this; 
	}
};

class C : public B
{
public:
	// virtual void print() { cout << "C\n"; }
	void print()
	{
		cout << "C\n";
	}
};

int main()
{
	A a;
	B b;

	// �θ��۷����� �ڽ� ���۷��� ����Ű��
	A& aref = b;
	aref.getThis()->print();
	b.getThis()->print();

	cout << typeid(aref.getThis()).name() << endl;
	cout << typeid(b.getThis()).name() << endl;

	return 0;
}