#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	{
		cout << "Enter a number \n";

		int i;
		cin >> i;

		cout << i << endl;
	}
	 
	{
		char buf[5];
		cin >> setw(5) >> buf;
		cout << buf;
	}
	
	return 0;
}