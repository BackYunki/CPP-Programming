#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	for (size_t i = 0; i < argc; i++)
	{
		string argv_single = argv[i];

		if (i == 0)
		{
			cout << "argv[0] is file path => " << argv_single << endl;
		}
		else
		{
			cout << i << ": " << argv_single << endl;
		}
	}
}