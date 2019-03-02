#include <iostream>

int main()
{
	using namespace std;

	//int value = 5;
	//const int *ptr = &value;	// 내가 가리키고 있는 주소 안에 있는 값을 안 바꾸겠다는 뜻
	//value = 6;// 은 되지만, *ptr = 6; 은 안 돼. 바뀐 값을 가져올 순 있어도 자기가 바꾸진 못 함.

	//int value2 = 6;
	//ptr = &value2;

	//cout << *ptr << endl;

	int value = 5;
	int* const ptr = &value;
	
	*ptr = 10;
	cout << *ptr << endl;

	int value2 = 8;
	//ptr = &value2; 포인터가 const 여서 주소는 못 바꾼다.


	return 0;
}