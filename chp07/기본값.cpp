#include <iostream>
#include <string>	
using namespace std;

//기본값이 있는 경우에는 헤더파일에 이렇게 해두는 게 좋다.
void print(int x = 10, int y = 20, int z = 30);

void print(int x, int y, int z) {}

// 이 경우 ambiguous 하다.
// print(10) 일 경우 아래꺼는 y가 생략된 거라서 y에 10이 들어갈 수도 있기 때문이다.
// 따라서 디폴트 값이 함수 오버로딩하는데 영향을 준다.
void print(int x) {}
void print(int x, int y = 10) {}

int main()
{
	//print(10);	

	return 0;
}