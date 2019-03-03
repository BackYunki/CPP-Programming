#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cassert>
#include <string.h>
#define MODIFIED_COPYCONSTRUCTOR
using namespace std;

class MyString
{
private:
	char* m_data   = nullptr;
	int   m_size = 0;

public:
	MyString(const char* source = "")
	{
		assert(source);
		m_size = strlen(source) + 1;	// 널문자 생각해서 하나 더 줘야함
		m_data = new char[m_size];

		// 0 1 2 3 4 5
		// y u n k i 0
		// m_length = 6;
		for (int i = 0; i < m_size; ++i)
			m_data[i] = source[i];
	}

#ifdef MODIFIED_COPYCONSTRUCTOR
	// 아직 안 만들었는데. 막아두고 싶으면 MyString(const MyString.. . ) = delete; 하면 됨
	MyString(const MyString& origin)
	{
		cout << "Copy Constructor Called.\n";
		m_size = origin.m_size;

		if (origin.m_data != nullptr)	// 얘가 할당 받지 못한 놈일 수 있기 때문에 검사하고 간다.
		{
			m_data = new char[m_size];

			for (int i = 0; i < m_size; i++)
			{
				m_data[i] = origin.m_data[i];
			}
		}
		else
		{
			cout << "Assertion Fail: origin string points nullptr\n";
			m_data = nullptr;
			exit(1);
		}
	}
#endif
	~MyString()
	{
		delete[] m_data;
	}

	friend ostream& operator << (ostream& out, const MyString& lhs)
	{
		out << lhs.m_data;
		return out;
	}

	MyString& operator = (const MyString& origin)
	{
		cout << "Assignment Operator Called.\n";
		if (this == &origin) return *this;	// 자기 자신에 자기자신을 넣을 수도 있을까봐. 바로 넘겨주기.
		
		delete[] m_data;	// 내가 이미 메모리를 갖고 있는 경우에는 내꺼 다시 반환하고 새거 넣어야해서

		m_size = origin.m_size;
		
		if (origin.m_data != nullptr)
		{
			m_data = new char[m_size + 1];
			for (int i = 0; i < m_size; i++)
				m_data[i] = origin.m_data[i];
		}
		else
		{
			cout << "Assertion Fail: origin string points nullptr\n";
			m_data = nullptr;
			exit(1);
		}

		return *this;
	}

	const char* getString() { return m_data; }
	int			getLength() { return m_size; }
};

int main()
{
	MyString my_str("yunki");

	cout << (int*)(my_str.getString()) << endl;
	cout << my_str.getString() << endl;

	{
		MyString copy = my_str;
		cout << (int*)copy.getString() << endl;
		cout << my_str.getString() << endl;
	}

	cout << my_str.getString() << endl;	// 기본 생성자의 얕은 복사로 인해서 값들이 복사되면서
										// 주소가 복사되고 코드블럭 안의 소멸자호출로 기존의 주소가 반환되어 버렸다.
										// 그리고 여기서 출력 후 반환하려니 이미 OS가 내 방을 빼버렸다...
										// 맨 위로 올라가서 매크로의 주석을 해제해보자.
	cout << '\n';
	MyString my_str2("taewon");

	cout << (int*)(my_str2.getString()) << endl;
	cout << my_str2.getString() << endl;

	my_str2 = my_str;
	cout << (int*)(my_str2.getString()) << endl;	// 대입 연산자로 인해서 동적할당 주소도 바꼈음.
	cout << my_str2 << endl;

	return 0;
}