#include <iostream>

int main()
{
	using namespace std;
	int length;

	cout << "Enter the length of an array >> ";
	cin >> length;
	int *arr = new int[length];
	
	for (size_t i = 0; i < length; i++)
	{
		cin >> arr[i];
		cout << arr[i] << endl;
	}
	
	delete[] arr;
}