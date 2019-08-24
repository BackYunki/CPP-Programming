#include <iostream>
#include <cctype>
#include <string>
#include <bitset>

using namespace std;

void printCharacterClassification(const int& i) 
{

}
void printStates(const std::ios& stream) 
{
	cout << boolalpha;
	cout << "good()=" << stream.good() << endl;
	cout << "eof()=" << stream.eof() << endl;
	cout << "fail()=" << stream.fail() << endl;
	cout << "bad()=" << stream.bad() << endl;
}
void isAllDigit(const string& str) {}

int main()
{
	while (true)
	{
		int i;
		cin >> i;

		// 인풋의 상태를 확인해보자.
		printStates(cin);

		//cout << boolalpha;
		//cout << std::bitset<8>(cin.rdstate()) << endl;
		//cout << std::bitset<8>(std::istream::goodbit) << endl; // good: 0 , eof: 1, fail: 2, bad: 4
		//cout << std::bitset<8>(std::istream::failbit) << endl;
		cout << !bool((cin.rdstate() & std::istream::failbit) != 0) << endl;

		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
	}

	return 0;
}