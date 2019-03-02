#include <iostream>
#include <typeinfo>
#include <bitset>

int main()
{
	using namespace std;

	//auto a = 123;

	//cout << typeid(a).name() << endl;

	//int b = 123.5;
	//cout << b << endl;	// �Ͻ��� ����ȯ�� �ż� �Ҽ����� �߷�������.

	//size_t c = 1234567890123456789;	// �굵 long long �� uint �� ���� �߸�
	//cout << typeid(c).name() << " => " << c << endl;

	//long long d = c;	// Numeric Promotion ����
	//cout << typeid(d).name() << " => " << d << endl;

	cout << "static cast\n";

	int i = 30001;
	char e = i;

	cout << "i = " << i << "\t => " << bitset<32>(i) << endl;
	//cout << "e = " << (int)e << "\t\t => " << bitset<32>(e) << endl;
	cout << "e = " << static_cast<int>(e) << "\t\t => " << bitset<32>(e) << endl;

	cout << "\n�Ҽ����� ����ȯ�� �Ҽ����� �߷�������.\n";
	double d = 0.123456789;
	float f = d;
	double long dl = 0.123456789;
	cout.precision(24);

	cout << "d : " << d << endl;
	cout << "f : " << f << endl;
	cout << "dl : " << dl << endl;
	return 0;
}