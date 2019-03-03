#include <iostream>
#include <cassert>
#include <array>	
using namespace std;

void printValue(const array<int, 5> &my_array, const int &idx)
{
	assert(idx >= 0);
	assert(idx <= my_array.size() - 1);
	cout << my_array[idx] << endl;
}

int main()
{
	// assert(이 조건을 꼭 만족해야만 넘거갈 수 있습니다.) 라고 단언하는 것임.
	// 그래서 조건식이 false 일 때 에러창을 띄움
	// 지정외의 행동을 하면 어디서 에러가 났는지 알려준다.
	// release 모드에서는 실행 안 된다. 보니까 컴파일 모드 아니면 0으로 되어있어서 실행 안 되게 한 거였음.
	array<int, 5> my_array{ 1,2,3,4,5 };
	
	int idx;
	cin >> idx;
	
	printValue(my_array, idx);

	return 0;
}