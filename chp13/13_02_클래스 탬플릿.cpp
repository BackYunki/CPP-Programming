#include "MyArray.h"
// #include "MyArray.cpp" <- 나중에 프로젝트가 커지면 문제가 생긴다. 이번에는 걍 헤더온리로 가즈아
using namespace std;

int main()
{
	// <> 안에는 컴파일 타임에 알려진 값들만 들어갈 수 있다. 변수 안 돼!!
	MyArray<double, 100> my_array;

	for (unsigned int i = 0; i < my_array.getLength(); i++)
	{
		my_array[i] = i * 10;
	}

	my_array.print();

	return 0;
}