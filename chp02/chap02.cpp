#include <iostream>
#include <cmath>
#include "defines.hpp"
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS

/*
' <- �̷� ���ͷ� ����� ó�� ���� �ż�.  0b11111111 ���� 0b1111'1111�� ����� ���� ����
'�� �����Ϸ��� �� ���� ����ģ��.
*/
int main()
{
	using namespace std;

	double radius;
	cin >> radius;
	double circumference = 2.0 * radius * constants::pi;

	return 0;
}