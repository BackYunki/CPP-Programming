#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	stringstream os;
	
	//int i = 12345;
	//double d = 67.89;

	//os << i << " " << d;

	os << "12345 67.89";

	int i2;
	double d2;

	os >> i2 >> d2;
	cout << i2 << "|" << d2 << endl;

	os.str("");
	os.clear();

	cout << "������Ʈ�� �ʱ�ȭ �� ����: " << os.str() << endl;
	/*string str1, str2;
	os >> str1 >> str2;

	cout << str1 << "|" << str2 << endl;*/

	return 0;
}