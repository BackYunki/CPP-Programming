#include <iostream>
#include <cassert>
#include <array>	
using namespace std;

int main()
{
	const int x = 10;

	assert(x == 5);

	//������ ������ ��� ����ش�. ��, ����� ������!
	//static_assert(x == 5, "x should be 5");

	return 0;
}