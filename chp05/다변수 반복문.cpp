#include <iostream>
#include <string>
#include <utility>
#include <bitset>

int main()
{
	using namespace std;

	for (size_t i = 0, j = 0; i+j < 10; ++i, j +=2)
	{
		cout << "i: " << i << " " << "j: " << j << '\n';
	}

	size_t i = 0;

	cout << i << "=" << bitset<32>(i) << endl;
	cout << --i << "=" << bitset<32>(i) << endl;

	return 0;
}