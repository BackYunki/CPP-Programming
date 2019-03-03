#include <iostream>
using namespace std;
/*
실수를 줄이기 위해 override 하겠다고 적어두는 것임. 인자가 달라서 오버라이딩 안 될 때도 빨간줄 쳐줌
*/
class A
{
public:
	//오버라이드 못 하게 final 을 쓸 수 있다.
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
	// 여기가 A의 print를 override 하겠다고 명시한 부분
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

	// 부모레퍼런스로 자식 레퍼런스 가리키기
	A& aref = b;
	aref.getThis()->print();
	b.getThis()->print();

	cout << typeid(aref.getThis()).name() << endl;
	cout << typeid(b.getThis()).name() << endl;

	return 0;
}