#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>
using namespace std;
int cnt = 0;
class Simple
{
private:
	int m_id;
public:
	Simple() : m_id(cnt++)
	{
		cout << 's' << m_id << "\'s Ctor has called.\n";
	}
	~Simple()
	{
		cout << 's' << m_id << "\'s Dtor has called.\n";
	}
};

class DynamicArray
{
private:
	int *m_arr = nullptr;
	int m_size = 0;
public:
	DynamicArray(const int& length_in)
	{
		m_size = length_in;
		m_arr = new int[m_size];
	}
	// new 뒤엔 반드시 delete가 와야한다.
	~DynamicArray()
	{
		// nullptr 인 경우 지우려면 문제가 발생하기 때문!
		if(m_arr != nullptr)
			delete[] m_arr;
	}

	int size() { return m_size; }
};

int main()
{
	//Simple s0;
	//Simple *s1 = new Simple();
	//Simple s2;

	//delete s1;	// delete 는 소멸자를 호출시킨다리

	while (true)
	{
		DynamicArray my_int_arr(10000);
	}

	return 0;
}