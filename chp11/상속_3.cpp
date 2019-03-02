#include <iostream>
using namespace std;

class Mother
{
private:
	int m_i;
protected:
	int m_prot;
public:
	int m_pub;

	Mother() {}
	Mother(const int & i) : m_i(i), m_prot(i)
	{
		cout << "Mother construction\n";
	}
	~Mother()
	{
		cout << "Mother destruction\n";
	}
};

class Child : private Mother
{
private:
	double m_d;
public:
	Child() : Mother(1024), m_d(1.0) // il에서 생성자 순서를 바꿔도 컴파일러는 부모클래스 먼저 초기화한다.
	{
		cout << Mother:: << endl;
		cout << "Child construction\n";
	}
	~Child()
	{
		cout << "Child destruction\n";
	}
};

int main()
{
	Child c1;

	cout << sizeof(Child) << '\n';	// 사이즈가 생각보다 크게 나오는데. 마더클래스를 충분히 담을 수 있게 하려고 하는 것이다.
	cout << sizeof(Mother) << '\n';
	
	return 0;
}