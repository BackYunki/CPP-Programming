#include <iostream>
using namespace std;

// void pointer = generic pointer 라고도 함.

enum Type
{
	INT,
	CHAR,
	FLOAT,
	DOUBLE,
};

int main()
{
	int		i = 5;
	float	f = 3.0f;
	char	c = 'a';

	void *ptr = nullptr;

	ptr = &i;
	ptr = &f;
	//ptr = &c;

	Type ptrType = FLOAT;

	// cout << ptr + 1 << endl;	// void이면 몇 바이트를 더해야할지 알 수 없음. int 면 4칸 갈텐데. void는 모르잖아!
	// cout << *ptr << endl;	// 어떤 타입인지 알 수 없어서 역참조도 안 된다. 정수를 표현한 걸로 넣은건지, 플로트인지 알 수 없잖아!
	cout << *static_cast<float*>(ptr) << endl;	// 강제 형변환을 해야 역참조가 된다.
	// 현실적으로 void 포인터를 사용할 일은 많지 않은데. 주소의 특징을 이해하는 데는 도움이 된다리

	// 굳이 쓴다면 아래와 같이 씀
	if (ptrType == FLOAT)
	{
		cout << *static_cast<float*>(ptr) << endl;
	}
	else if (ptrType == INT)
	{
		cout << *static_cast<int*>(ptr) << endl;
	}
	else if (ptrType == CHAR)
	{
		cout << *static_cast<char*>(ptr) << endl;
	}
	else
	{
		cout << *static_cast<double*>(ptr) << endl;
	}
	return 0;
}