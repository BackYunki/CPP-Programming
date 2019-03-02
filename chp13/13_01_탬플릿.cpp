// ���ø��� ���α׷��Ӱ� �� ���� �����Ϸ����� �Ѱ��ִ� ���̴�.
// template<typename T> �� template<class T> �� ���� ����� �����̴�. Ŭ������ �� ���� �ִٰ� �ؼ� class �� �� ��.
#include <iostream>
#include "Cents.h"
using namespace std;

// ���ø����� ������� ��ü���� ��� �ν��Ͻ���.
template<class T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

int main()
{
	cout << getMax(1, 2)		<< endl;
	cout << getMax(3.14, 1.592) << endl;
	cout << getMax(1.f, 3.4f)	<< endl;
	cout << getMax('a', 'c')	<< endl;
	// cout << getMax(3.14, 5) << endl; Ÿ���� �ٸ��� �� �ǳ�..!
	putchar('\n');

	cout << getMax(Cents(5), Cents(10)) << endl;

	return 0;
}