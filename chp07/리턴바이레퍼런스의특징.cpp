#include <iostream>
#include <vector>

using namespace std;

/*

 return by reference 는 수학식 같은 곳에 쓸 수 있다.
 (함수) *2 = 5;
 이렇게 결과가 즉각적으로 보이게끔.

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