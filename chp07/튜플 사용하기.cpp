#include <iostream>
#include <tuple>
using namespace std;

tuple<int, double> getTuple()
{
	int a = 10;
	double d = 3.14;
	
	return std::make_tuple(a, d);
}

int main()
{
	//tuple<int, double> myTuple = getTuple();
	//cout << get<0>(myTuple) << endl;
	//cout << get<1>(myTuple) << endl;

	auto[a, d] = getTuple();
	cout << a << endl;
	cout << d << endl;

	return 0;
}