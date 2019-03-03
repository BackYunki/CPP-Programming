#include <iostream>

int main()
{
	using namespace std;

	char ch = 'c';

	cout << (uintptr_t)&ch << endl;	// ch는 캐릭터여서 캐릭터의 주소를 주니 얘는 문자열인가
									// 라고 착각을하여 null 문자 나올 때까지 읽다보니 이상한
									// 문자가 나오는 것임!!!!!

	return 0;
}