#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>
using namespace std;

class Something
{
public:
	static constexpr int s_value = 1; // constexpr �� ���ͷ�ó�� ������ Ÿ�ӿ� ���� ���������Ѵ�.

};

//int Something::s_value = 1; <- const ���������� ���� �� ��!

//int generateID()
//{
//	static int s_id = 0;
//	return ++s_id;
//}

int main()
{
	//cout << generateID() << endl;
	cout << Something::s_value << endl;
	
	Something s1;
	//s1.s_value = 10; <- ��� ���������� ���� �� ��!

	cout << s1.s_value << endl;

	return 0;
}