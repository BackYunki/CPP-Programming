#include <iostream>
using namespace std;

static int num = 0;

class Test
{
private:
	int m_value;
public:
	Test()
	{
		m_value = ++num;
		cout << m_value << ": Constructor Called.\n";
	}
	Test(const Test& origin)
	{
		this->m_value = ++num;
		cout << "Copy Constructor Called.\n";
	}
	~Test()
	{
		cout << m_value << ": Destructor Called.\n";
	}
};

int main()
{
	Test t1;
	Test t2(t1);

	int a = 1, b = 2;
	const int& c = a + b;
	int&& d = a + b;
	cout << d << endl;


	return 0;
}