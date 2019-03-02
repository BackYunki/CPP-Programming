#include <iostream>
using namespace std;

int main()
{
	//int *ptr = nullptr;
	//int **ptrptr = nullptr;

	//int value = 5;

	//ptr = &value;
	//ptrptr = &ptr;
	//
	//cout << ptr << " " << *ptr << " " << &ptr << endl;
	//cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl;
	//cout << **ptrptr << endl;

	const int row = 3;
	const int col = 5;

	int arr[row][col] 
	{
		{1,2,3,4,5},
		{2,3,4,5,6},
		{3,4,5,6,7}
	};
	
	int **matrix = new int*[row];

	for (size_t r = 0; r < row; ++r)
		matrix[r] = new int[col];

	for (size_t r = 0; r < row; r++)
	{
		for (size_t c = 0; c < col; c++)
		{
			matrix[r][c] = arr[r][c];
			cout << matrix[r][c] << ' ';
		}
		cout << endl;
	}

	cout << "\n1차원으로도 출력 할 수 있다.\n";
	int *linear = new int[row*col];
	for (size_t r = 0; r < row; ++r)
	{
		for (size_t c = 0; c < col; ++c)
		{
			linear[c + col * r] = arr[r][c];
			cout << linear[c + col * r] << ' ';
		}
		cout << endl;
	}

	for (size_t r = 0; r < row; ++r)
	{
		delete matrix[r];
	}
	delete[] matrix;

	delete[] linear;

	return 0;
}