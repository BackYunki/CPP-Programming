#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>
using namespace std;

class B
{
private:
	int m_b;

public:
	B(const int& m_b_in) 
		: m_b(m_b_in)
	{}
};

class Something
{
private:
	int		m_i = 100;
	double	m_d = 100.0f;
	char	m_c = 'F';
	int		arr[5] = { 100, 200 ,300, 400, 500 };
	B		m_b{ 1024 };

public:
	Something() : 
		  m_i{ 1 }
		, m_d{ 3.14 }
		, m_c{ 'a' }
		, arr{ 1,2,3,4,5 }	// () 대신 컬리 브레킷을 쓰면 타입체킹해준다.
		, m_b{ m_i - 1 }
	{
		m_i *= 2;
		m_d *= 2;
		m_c += 1;
	}
	
	void print()
	{
		cout << m_i << ", " << m_d << ", " << m_c << '\n';
		for (const auto& e : arr)
			cout << e << ' ';
		cout << '\n';
	}
};

int main()
{
	Something my_something;
	my_something.print();
	return 0;
}