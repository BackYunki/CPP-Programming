#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v{ 1,2,3 };
	// v.reserve(1024);
	// reserve 를 쓰면 공간을 미리 할당해둬서 뉴, 딜리트를 확보된 공간 안에서 많이 안 할 수 있어 속도가 증가한다.

	// 데이타 함수를 쓰면 주소를 받아와서 포인터로 접근할 수 있다.
	// int *ptr = v.data();

	v.resize(2);
	for (auto& e : v)
	{
		cout << e << ' ';
	}
	cout << '\n';
	cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;
	//용량은 3인데. 지금 v[2] 부터는 접근을 막아놨다. 포인터로 접근해보자.
	int* ptr = v.data();
	cout << ptr[2] << endl;
	//사이즈는 읽을 수 있는 양이라는 것을 알 수 있다!
	return 0;
}