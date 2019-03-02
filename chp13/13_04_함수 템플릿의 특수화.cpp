#include "Storage.h"
//#include "Storage.cpp"
using namespace std;

template<typename T>
T getMax(T a, T b)
{
	return a > b ? a : b;
}

template<>
char getMax(char a, char b)
{
	cout << "경고 : 문자를 비교하고 있습니다\n";
	return a > b ? a : b;
}

int main()
{
	//cout << getMax('A', 'B') << endl;

	Storage<int> iValue(5);
	Storage<double> dValue(6.7);

	iValue.print();
	dValue.print();

	return 0;
}