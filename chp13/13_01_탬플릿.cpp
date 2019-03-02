// 탬플릿은 프로그래머가 할 일을 컴파일러에게 넘겨주는 것이다.
// template<typename T> 랑 template<class T> 는 거의 비슷한 개념이다. 클래스가 올 수도 있다고 해서 class 가 된 듯.
#include <iostream>
#include "Cents.h"
using namespace std;

// 탬플릿으로 만들어진 객체들은 모두 인스턴스다.
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
	// cout << getMax(3.14, 5) << endl; 타입이 다르니 안 되네..!
	putchar('\n');

	cout << getMax(Cents(5), Cents(10)) << endl;

	return 0;
}