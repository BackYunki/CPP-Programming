#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int& getValue(int x)
{
	int value = x * 2;
	
	//cout << "in getValue() : value's address = " << &value << endl;
	
	return value;
}

int main()
{
	//int& ref = getValue(n);
	int &m = getValue(5);
	//cout << "in main() : ref's address = " << &ref << endl;
	for (size_t i = 0; i < 100; i++)
	{
		cout << m << endl;
	}
	return 0;
}