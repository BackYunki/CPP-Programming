#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
	구조체는 access specifier 가 안 들어감
	public:  이런거 음슴
*/

//struct Friend
//{
//	string name;
//	string address;
//	int	   age;
//	double height;
//	double weight;
//
//	void print()
//	{
//		cout << name << ", " << address << ", " << address << ", " << height << ", " << weight << endl;
//	}
//};

//void print(const string &name, const string &address, const int &age, const double &height, const double &weight)

//void print(const Friend &fr)
//{
//	cout << fr.name << fr.address << fr.address << fr.height << fr.weight << endl;
//}

class Friend
{
public:
	string m_name;
	string m_address;
	int	   m_age;
	double m_height;
	double m_weight;

	void print()
	{
		cout << m_name << ", " << m_address << ", " << m_address << ", " << m_height << ", " << m_weight << endl;
	}
};

int main()
{
	Friend jj{"jack jack", "Uptown", 2, 160, 28};	// 값을 넣어줘서 얘는 인스턴스라고 함.

	jj.print();

	vector<Friend> my_friends;
	my_friends.resize(2);

	for (auto &e : my_friends)
		e.print();

	return 0;
}