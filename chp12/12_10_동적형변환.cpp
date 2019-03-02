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
	
	// 다형성 출력 : m_j 에 접근할 수가 없다.
	base_ptr->print();
	cout << base_ptr->m_i << endl;
	// cout << base_ptr->m_j << endl;
	printf("base_ptr 의 사이즈: %d\n", sizeof(*base_ptr));
	printf("derv1 의 사이즈: %d\n", sizeof(derv1));

	// 동적 형변환으로 접근하기: 힙에 메모리는 그대로 남아있기 때문에 가능하다. 실패하면 null 을 리턴한다.
	auto *base_to_d1 = dynamic_cast<Derived1*>(base_ptr);
	base_to_d1->print();
	cout << base_to_d1->m_i << endl;
	cout << base_to_d1->m_j << endl;

	// 이 상황에서 base_ptr은 derv1 을 가리키고 있다. 여기서 bast_ptr 을 derived2로 동적 형변환하면 안 되겠지?
	// 그래서 null  이 나온다.
	auto *base_to_d2 = dynamic_cast<Derived2*>(base_ptr);
	if (base_to_d2 == nullptr) cout << "Fail!\n";

	// 정적 캐스팅은 특이하게도 알아서 최대한 형변환을 해준다리... 그리고 스태틱캐스트는 컴파일타임에 에러 잡아줘서
	// 런타임에 null 채킹이 의미가 없다리..
	auto *base_to_d2_v2 = static_cast<Derived2*>(base_ptr);
	printf("정적변환시 사이즈: %d\n", sizeof(*base_to_d2_v2));
	auto *base_to_d2_v3 = static_cast<Derived2*>(base_ptr);
	
	if (base_to_d2_v3 == nullptr)
	{
		cout << "Static casting failed.\n";
	}
	else
	{
		base_to_d2_v3->print();
		printf("base_to_d2_v2의 포인터 주소: %p\n", base_to_d2_v3);
		printf("base_to_d2_v2의 사이즈: %d\n", sizeof(*base_to_d2_v3));
	}

	return 0;
}