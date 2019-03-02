#include <iostream>
#include <typeinfo>
#include <bitset>

int main()
{
	using namespace std;

	//auto a = 123;

	//cout << typeid(a).name() << endl;

	//int b = 123.5;
	//cout << b << endl;	// 암시적 형변환이 돼서 소숫점이 잘려나간다.

	//size_t c = 1234567890123456789;	// 얘도 long long 이 uint 에 들어가서 잘림
	//cout << typeid(c).name() << " => " << c << endl;

	//long long d = c;	// Numeric Promotion 승진
	//cout << typeid(d).name() << " => " << d << endl;

	cout << "static cast\n";

	int i = 30001;
	char e = i;

	cout << "i = " << i << "\t => " << bitset<32>(i) << endl;
	//cout << "e = " << (int)e << "\t\t => " << bitset<32>(e) << endl;
	cout << "e = " << static_cast<int>(e) << "\t\t => " << bitset<32>(e) << endl;

	cout << "\n소숫점의 형변환은 소숫점이 잘려나간다.\n";
	double d = 0.123456789;
	float f = d;
	double long dl = 0.123456789;
	cout.precision(24);

	cout << "d : " << d << endl;
	cout << "f : " << f << endl;
	cout << "dl : " << dl << endl;
	return 0;
}