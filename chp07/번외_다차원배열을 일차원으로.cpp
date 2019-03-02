#include <iostream>
#include <vector>
using namespace std;

int main()
{
	const int X = 3, Y = 3, Z = 2, W = 5;
	int arr[X][Y][Z] 
	{ 
		{ {1,2}, {2,3}, {3,4} },
		{ {4,5}, {5,6}, {6,7} },
		{ {7,8}, {8,9}, {10,11} }
	};
	int arr02[X*Y*Z];
	for (size_t i = 0; i < X; i++)
	{
		for (size_t j = 0; j < Y; j++)
		{
			for (size_t k = 0; k < Z; k++)
			{
				arr02[k + (Z*j) + (Y*Z*i)] = arr[i][j][k];

				cout << k + (Z*j) + (Y*Z*i) << ": ";
				cout << arr02[k + (Z*j) + (Y*Z*i)] << '\n';
			}
		}
	}

	//X = 3, Y = 3, Z = 2, W = 5;
	int temp = 0;
	for (size_t i = 0; i < X; i++)
	{
		for (size_t j = 0; j < Y; j++)
		{
			for (size_t k = 0; k < Z; k++)
			{
				for (size_t l = 0; l < W; l++)
				{
					cout << (l + (Y*Z*W*i) + (Z*W*j) + (W*k)) << ": " << temp++ << endl;
				}
			}
		}
	}
	return 0;
}