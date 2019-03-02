#include <iostream>
#include <cmath>

using namespace std;

void addOne(int &y)
{
	y += 1;
}

int main()
{
	int x = 5;
	cout << x << ": " << &x << endl;
	
	addOne(x);

	cout << x << ": " << &x << endl;
	return 0;
}