#include <iostream>
#include <vector>

using namespace std;

/*

 return by reference �� ���н� ���� ���� �� �� �ִ�.
 (�Լ�) *2 = 5;
 �̷��� ����� �ﰢ������ ���̰Բ�.

 */
int& get(vector<int> &vec, const int idx)
{
	return vec[idx];
}

int main()
{
	vector<int> vec{ 1, 2, 3, 4 };
	vec[0] = 10;

	get(vec, 0) *= 2;

	cout << vec[0] << endl;

	return 0;
}