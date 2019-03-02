#include <iostream>
#include <array>	
#include <algorithm>

using namespace std;

void printArray(const array<int, 5> &arr)
{
	for (auto &element : arr)
	{
		cout << element << ' ';
	}
	cout << endl;
	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	array<int, 5> temp { 3, 15, 2, 4, 1 };
	sort(temp.begin(), temp.end());
	for (auto &element : temp)
	{
		cout << element << ' ';
	}
	cout << endl;
}

int main()
{
	array<int, 5> my_arr = { 1, 2, 3, 4, 5 };
	// at 은 범위 검사를 해준다. 대신 속도가 조금 느려져서 퍼포먼스 생각하면 인덱싱이 더 빠르다.
	my_arr = { 1, 2, 3, }; // 적게는 넣어도 된다. 없는 건 알아서 0으로 채워 넣음.
	// my_arr = { 1, 2, 3, 4, 5, 6 };
	printArray(my_arr);

	return 0;
}