#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main()
{
	using namespace std;

	typedef float distance_t;
	typedef vector<pair<string, int>> pairlist_t;
	int8_t ch(0);
	cout << ch << endl;

	pairlist_t p1;
	p1.push_back(make_pair("¹éÀ±±â", 25));
	cout << p1.back().first << ": " << p1.back().second << endl;

	return 0;
}