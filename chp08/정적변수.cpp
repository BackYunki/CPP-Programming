#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>
using namespace std;

class Something
{
public:
	static constexpr int s_value = 1; // constexpr 는 리터럴처럼 컴파일 타임에 값이 정해져야한다.

};

//int Something::s_value = 1; <- const 정적변수라 수정 못 해!

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
	//s1.s_value = 10; <- 상수 정적변수라 수정 못 해!

	cout << s1.s_value << endl;

	return 0;
}