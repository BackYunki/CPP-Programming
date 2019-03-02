#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> arr{ 1, 2, 3, 4, 5 };
	arr.resize(2);

	for (auto &e : arr)
	{
		cout << e << ' ';
	}
	cout << endl;
	return 0;
}