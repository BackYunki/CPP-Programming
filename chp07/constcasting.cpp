#include <iostream>

using namespace std;



int main()
{
	//static const int* arr = (const int[]) { 1, 2, 3, 4, 5 };

	// 문자열 리터럴은 특별히 취급됩니다. 그리고 프로그램의 데이터 영역에 바이너리로 저장이 됩니다.
	// 그리고 const char* str = "Hello"; 는 "Hello"라는 어딘가에 저장되어 있는 익명의
	// 배열로 취급합니다. 그리고 그곳의 첫 번째 주소에 str 포인터가 연결됩니다.
	// 그치만 static const 즉 전역 상수로 초기화를 한 배열!의 경우에는 문자열처럼 정의를 할 수 있어요.

	//char* s1 = "hello";
	//char ch = s1[0];
	//char* ch_ptr = &ch;

	//cout << ch_ptr << endl;

	// static const 배열의 효과: 문자열 리터럴이 사용할 동일한 상수 공간을 익명 객체가 아닌
	// 명명된 변수로 할당하는 것입니다.
	// 문자열도 같은 방식으로 명시적으로 만들 수 있습니다.
	static const int intstatic[] = { 3, 54, 12, 53 };
	static const char str[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
	const char* str1 = "Hello";
	const char* str2 = "Hello";

	cout << "스트링 풀에서 가져다 쓰기 때문에. 같은 문자열이면 같은 주소로 가서 사본이 안 생기게 한다.\n";
	cout << (int)str1 << endl;
	cout << (int)str2 << endl;

	cout << str << endl;
	for (const auto& n : intstatic)
	{
		cout << n << ' ';
	}

	return 0;
}