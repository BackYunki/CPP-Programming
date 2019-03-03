#include <iostream>
#include <cmath>
#include "defines.hpp"
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS

/*
' <- 이런 리터럴 상수는 처음 보는 거셈.  0b11111111 보다 0b1111'1111이 보기더 좋음 ㅎㅎ
'는 컴파일러가 안 보고 지나친당.
*/
int main()
{
	using namespace std;

	double radius;
	cin >> radius;
	double circumference = 2.0 * radius * constants::pi;

	return 0;
}