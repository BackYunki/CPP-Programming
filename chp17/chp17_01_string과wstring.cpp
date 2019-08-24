#include <string>
#include <iostream>
#include <locale>
#include <cstddef>
#include <cstdlib>
using namespace std;

int main(void)
{
	// c-style string example
	{
		char* strHello = new char[7];
		strcpy_s(strHello, sizeof(char) * 7, "hello!");
		
		cout << strHello << endl;
		delete[] strHello;
	}

	// basic_string<>, string, wstring
	{
		string string;
		wstring wstring;

		wchar_t wc;
	}
}