#include <iostream>

int main()
{
	using namespace std;

	//// uniform initializer 로 해보자
	//int *ptr = new (std::nothrow) int{ 1 };	// nothrow 를 사용하면 할당 못 받으면 nullptr이 들어간데.
	//										// 프로그램이 죽는 것보단 낫겠지.
	//if (ptr != nullptr)
	//{
	//	cout << *ptr << endl;
	//}
	//else
	//{
	//	cout << "메모리를 할당 받지 못 했습니다.\n";
	//}
	//delete ptr;

	// 위험한 짓
	while (true)
	{
		int *temp = new int;
		cout << temp << endl;
		delete temp;	// <- 요거 안 해주면 메모리 할당 계속 돼서 나중에 힙 터질것임 ㅎㅎ
	}

	return 0;
}