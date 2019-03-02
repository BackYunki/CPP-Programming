#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Base
{
public:
	int m_i = 0;
	
	virtual void print()
	{
		cout << "I'm Base\n";
	}
};

class Derived1 : public Base
{
public:
	int m_j = 1024;

	virtual void print() override
	{
		cout << "I'm derived1.\n";
	}
};

class Derived2 : public Base
{
public:
	string m_name = "Dr.Two";

	virtual void print() override
	{
		cout << "I'm derived2.\n";
	}
};

int main()
{
	Derived1 derv1;
	Base *base_ptr = &derv1;
	
	// ������ ��� : m_j �� ������ ���� ����.
	base_ptr->print();
	cout << base_ptr->m_i << endl;
	// cout << base_ptr->m_j << endl;
	printf("base_ptr �� ������: %d\n", sizeof(*base_ptr));
	printf("derv1 �� ������: %d\n", sizeof(derv1));

	// ���� ����ȯ���� �����ϱ�: ���� �޸𸮴� �״�� �����ֱ� ������ �����ϴ�. �����ϸ� null �� �����Ѵ�.
	auto *base_to_d1 = dynamic_cast<Derived1*>(base_ptr);
	base_to_d1->print();
	cout << base_to_d1->m_i << endl;
	cout << base_to_d1->m_j << endl;

	// �� ��Ȳ���� base_ptr�� derv1 �� ����Ű�� �ִ�. ���⼭ bast_ptr �� derived2�� ���� ����ȯ�ϸ� �� �ǰ���?
	// �׷��� null  �� ���´�.
	auto *base_to_d2 = dynamic_cast<Derived2*>(base_ptr);
	if (base_to_d2 == nullptr) cout << "Fail!\n";

	// ���� ĳ������ Ư���ϰԵ� �˾Ƽ� �ִ��� ����ȯ�� ���شٸ�... �׸��� ����ƽĳ��Ʈ�� ������Ÿ�ӿ� ���� ����༭
	// ��Ÿ�ӿ� null äŷ�� �ǹ̰� ���ٸ�..
	auto *base_to_d2_v2 = static_cast<Derived2*>(base_ptr);
	printf("������ȯ�� ������: %d\n", sizeof(*base_to_d2_v2));
	auto *base_to_d2_v3 = static_cast<Derived2*>(base_ptr);
	
	if (base_to_d2_v3 == nullptr)
	{
		cout << "Static casting failed.\n";
	}
	else
	{
		base_to_d2_v3->print();
		printf("base_to_d2_v2�� ������ �ּ�: %p\n", base_to_d2_v3);
		printf("base_to_d2_v2�� ������: %d\n", sizeof(*base_to_d2_v3));
	}

	return 0;
}