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
	// at �� ���� �˻縦 ���ش�. ��� �ӵ��� ���� �������� �����ս� �����ϸ� �ε����� �� ������.
	my_arr = { 1, 2, 3, }; // ���Դ� �־ �ȴ�. ���� �� �˾Ƽ� 0���� ä�� ����.
	// my_arr = { 1, 2, 3, 4, 5, 6 };
	printArray(my_arr);

	return 0;
}