#include <iostream>
#include "MyConstants.h"

using namespace std;

// 전방선언 : extern(al) 은 다른 cpp파일에서도 해당 멤버를 쓸 수 있다. 
extern void doSomething();
//extern int a;

int main()
{
	// cpp 파일이 다를 때 constants 네임스페이스의 상수값들의 주소가 다르다는 걸 알 수 있다.
	// 그런데 header 파일엔 선언만 해두고 cpp 파일에 복사해서 값을 정의해주면 같은 주소를 갖는다.
	cout << "In main.cpp file " << Constants::pi << " 주소: " << &Constants::pi << endl;
	doSomething();
	return 0;
}