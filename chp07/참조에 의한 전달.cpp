#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void printElements(int (&arr)[4])
{
	for (const auto& element : arr)
	{
		cout << element << ' ';
	}
	cout << endl;
}

void printVector(const vector<int> &v)
{
	for (const auto& element : v)
	{
		cout << element << ' ';
	}
	cout << endl;

	for (auto i = v.begin(); i !=  v.end(); ++i)
	{
		cout << *i << ' ';
	}
	cout << endl;
}

void foo(int* &int_ptr)
{
	cout << "after// in foo(): a = " << *int_ptr << ", address = " << (int)int_ptr << endl;
	cout << "in foo: ptr's address = " << (int)&int_ptr << endl;
	*int_ptr = 6;
}

// const 면 입력이겠고 그냥 레퍼런스면 출력이겠구나를 알 수 있음.
void getSinCos(const double &degrees, double &sin_out, double &cos_out)
{
	static const double pi = 3.141592 / 180.0;
	const double radians = degrees * pi;
	sin_out = sin(radians);
	cos_out = cos(radians);
}

void addOne(int &y)
{
	cout << "value at addOne(): " << y << "\taddress: " << &y << endl;

	y = y + 1;
}

int main()
{
	int x = 5;
	cout << "value: " << x << "\taddress: "<< &x << endl;
	addOne(x);
	cout << "value: " << x << "\taddress: " << &x << endl;

	cout << '\n';

	double sin(0.0);
	double cos(0.0);

	double degrees = 0.f;
	cin >> degrees;

	getSinCos(degrees, sin, cos);

	cout << "sin(" << degrees << ") = " << sin << endl;
	cout << "cos(" << degrees << ") = " << cos << endl;

	int a = 5;
	int* ptr_int = &a;
	cout << "before// in main(): a = " << a << ", address = " << (int)&a << endl;
	cout << "in main(): ptr's address = " << (int)&ptr_int << endl;
	foo(ptr_int);
	cout << "after// in main(): a = " << a << ", address = " << (int)&a << endl;
	
	int arr[]{ 1, 2, 3, 4 };
	printElements(arr);

	vector<int> vec{ 1,2,3,4 };
	printVector(vec);

	return 0;
}