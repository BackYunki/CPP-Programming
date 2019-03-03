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
		m_size = strlen(source) + 1;	// �ι��� �����ؼ� �ϳ� �� �����
		m_data = new char[m_size];

		// 0 1 2 3 4 5
		// y u n k i 0
		// m_length = 6;
		for (int i = 0; i < m_size; ++i)
			m_data[i] = source[i];
	}

#ifdef MODIFIED_COPYCONSTRUCTOR
	// ���� �� ������µ�. ���Ƶΰ� ������ MyString(const MyString.. . ) = delete; �ϸ� ��
	MyString(const MyString& origin)
	{
		cout << "Copy Constructor Called.\n";
		m_size = origin.m_size;

		if (origin.m_data != nullptr)	// �갡 �Ҵ� ���� ���� ���� �� �ֱ� ������ �˻��ϰ� ����.
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
		if (this == &origin) return *this;	// �ڱ� �ڽſ� �ڱ��ڽ��� ���� ���� �������. �ٷ� �Ѱ��ֱ�.
		
		delete[] m_data;	// ���� �̹� �޸𸮸� ���� �ִ� ��쿡�� ���� �ٽ� ��ȯ�ϰ� ���� �־���ؼ�

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

	cout << my_str.getString() << endl;	// �⺻ �������� ���� ����� ���ؼ� ������ ����Ǹ鼭
										// �ּҰ� ����ǰ� �ڵ�� ���� �Ҹ���ȣ��� ������ �ּҰ� ��ȯ�Ǿ� ���ȴ�.
										// �׸��� ���⼭ ��� �� ��ȯ�Ϸ��� �̹� OS�� �� ���� �����ȴ�...
										// �� ���� �ö󰡼� ��ũ���� �ּ��� �����غ���.
	cout << '\n';
	MyString my_str2("taewon");

	cout << (int*)(my_str2.getString()) << endl;
	cout << my_str2.getString() << endl;

	my_str2 = my_str;
	cout << (int*)(my_str2.getString()) << endl;	// ���� �����ڷ� ���ؼ� �����Ҵ� �ּҵ� �ٲ���.
	cout << my_str2 << endl;

	return 0;
}