#include <iostream>
#include <cassert>
#include <array>	
using namespace std;

int main()
{
	const int x = 10;

	assert(x == 5);

	//컴파일 이전에 경고를 띄워준다. 단, 상수만 가능해!
	//static_assert(x == 5, "x should be 5");

	return 0;
}