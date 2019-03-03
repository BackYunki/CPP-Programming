#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class IntList
{
private:
	int m_list[10]{ 1,2,3,4,5,6,7,8,9,10 };

public:
	int & operator [] (const int& index)
	{
		cout << "�� ���� �� ����?\n";
		//assert(index >= 0);
		assert(index < 10);
		
		return m_list[index];
	}

	const int & operator [] (const int& index) const
	{
		//assert(index >= 0);
		//assert(index < 10);

		return m_list[index];
	}
};


int main()
{
	const IntList list;
	//list[9] = 10; <= const ������ ����� ���� �� ��!
	
	cout << list[9] << endl;
	cout << list[11] << endl;
	
	IntList list2;
	cout << list2[0] << endl;

	return 0;
}