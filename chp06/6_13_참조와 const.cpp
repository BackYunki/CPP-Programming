#include <iostream>
using namespace std;

void doSomething(const int& ref)
{
	cout << ref << endl;
}

int main()
{
	int a = 1;
	
	doSomething(a);
	doSomething(1);
	doSomething(a + 1);
	doSomething(3 * 4);

	return 0;
}