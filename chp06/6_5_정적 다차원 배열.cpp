#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int arr[5][5];

	int cnt = 0;
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			arr[i][j] = cnt++;
			cout << "[" << i << "," << j << "]" << "=" << setfill(' ') << setw(3) << arr[i][j] << '\t';
		}
		cout << '\n';
	}

	return 0;
}