#include <iostream>
using namespace std;

namespace temp
{
	int a = 10;
	namespace temp2
	{
		int a = 20;
	}
};

namespace temp3::temp2::temp1
{
	int a = 30;
}
int main()
{
	// scope: ������ �� �� �ִ� ����
	cout << temp::a << endl;
	cout << temp::temp2::a << endl;
	cout << temp3::temp2::temp1::a << endl;
	return 0;
}