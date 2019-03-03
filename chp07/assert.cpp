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
	// assert(�� ������ �� �����ؾ߸� �ѰŰ� �� �ֽ��ϴ�.) ��� �ܾ��ϴ� ����.
	// �׷��� ���ǽ��� false �� �� ����â�� ���
	// �������� �ൿ�� �ϸ� ��� ������ ������ �˷��ش�.
	// release ��忡���� ���� �� �ȴ�. ���ϱ� ������ ��� �ƴϸ� 0���� �Ǿ��־ ���� �� �ǰ� �� �ſ���.
	array<int, 5> my_array{ 1,2,3,4,5 };
	
	int idx;
	cin >> idx;
	
	printValue(my_array, idx);

	return 0;
}