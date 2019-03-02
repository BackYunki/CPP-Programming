#include <iostream>

void inline swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void selection_sort(int arr[], int size)
{
	for (int i = 0; i < size-1; i++)
	{
		int min = i;
		for (int j = i+1; j < size; j++)
			if (arr[min] > arr[j]) min = j;
	
		swap(arr[i], arr[min]);
	}
}

int main()
{
	using namespace std;
	
	const int size = 5;
	int arr[size] = { 0, };

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter an integer[" << (i + 1) << "/" << size << "] >> ";
		cin >> arr[i];
	}
	cout << "Before Sorting\n";
	for (size_t i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << endl;

	selection_sort(arr, size);

	cout << "After Sorting\n";
	for (size_t i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
}