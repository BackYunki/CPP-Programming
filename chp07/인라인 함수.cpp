#include <iostream>

using namespace std;

inline int min(const int x, const int y)
{
	return x > y ? y : x;
}

int main()
{
	// inline: 라인 안으로, 코드 안으로 직접 들어간다는 의미
	// inline 은 매크로마냥 컴파일러가 코드를 함수 자체로 복붙 해버려서 
	// 함수 호출이 안 일어나게 하는데. 속도가 빨라지지만 프로그램 덩치가 커진다.
	// 요즘 컴파일러는 꼭 그렇게 하는 건 아니라고 한다. 참고만 할 뿐.
	// 그리고 안 붙여도 필요하면 인라인으로 바꿔버린다고 하넹.
	
	// 함수를 호출하려면 호출 주소로 점프 했다가 저장된 복귀주소로 다시 돌아가야하는데. 이게 또 일이란 말이야
	// 그래서 인라인 함수를 쓰는 거얌
	cout << min(3, 5) << endl;
	cout << (3 > 5 ? 5 : 3) << endl;

	return 0;
}