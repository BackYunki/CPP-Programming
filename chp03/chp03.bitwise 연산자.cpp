#include <iostream>
#include <bitset>
#include <iomanip>
//#define module01

int main()
{
	using namespace std;
#ifdef module01

	size_t a = 0b1100;
	size_t b = 0b0110;

	cout << a << ":\t" << bitset<4>(a) << endl;
	cout << b << ":\t" << bitset<4>(b) << endl;

	cout << "&:\t" << bitset<4>(a & b) << endl;
	cout << "|:\t" << bitset<4>(a | b) << endl;
	cout << "^:\t" << bitset<4>(a ^ b) << endl;

#endif
	// bool 8������ unsigned char 1���� �ϴ� �� �� ����.
	const size_t opt0 = 1 << 0;
	const size_t opt1 = 1 << 1;
	const size_t opt2 = 1 << 2;
	const size_t opt3 = 1 << 3;
	
	unsigned char items_flag = 0;
	
	cout << "No Item: " << bitset<8>(items_flag) << endl;

	items_flag |= opt1;
	cout << "Item01 optained: " << bitset<8>(items_flag) << endl;

	//items_flag &= ~opt1;
	//cout << "Item01 lost: " << bitset<8>(items_flag) << endl;

	// has item01? "�̷��� �ϸ� ������ ��ü�� 0�� �Ǿ�����ϴ�. �׷��� else������ ������.\n";
	if (items_flag & opt1)
	{
		cout << "you have the item01.\n";
	}
	else
	{
		cout << "you don't have item01.\n";
	}

	cout << endl;
	// optain item 2,3 
	items_flag |= (opt2 | opt3);

	cout << bitset<8>(opt2 | opt3) << endl;
	cout << "item 2,3 optained: " << bitset<8>(items_flag) << endl;
	


	return 0;
}