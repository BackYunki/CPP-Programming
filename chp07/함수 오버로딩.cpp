#include <iostream>
#include <string>
using namespace std;

int add(int x, int y)
{
	return x + y;
}

// 리턴값만 다르다고 오버로딩이 되는 건 아니다.
//double add(int x, int y)
//{
//	return x + y;
//}

double add(int x, int y, int z)
{
	return x + y + z;
}

// 오버로딩의 모호성
void print(float value)
{
	cout << value << endl;
}

void print(size_t value)
{
	cout << value << endl;
}

int main()
{
	//print(3.14);
	//print(10);

	print(3.14f);
	print(10u);
	
	return 0;
}