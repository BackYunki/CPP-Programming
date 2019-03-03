#include <iostream>

using namespace std;

class Accumulator
{
private:
	int m_counter = 0;

// Functor 라고 하는데. 마치 함수를 호출하는 것같은 효과를 줌.
public:
	int& operator() (const int& i) { return (m_counter += i); }
};

int main()
{
	Accumulator acc;
	cout << acc(10) << endl;
	cout << acc(20)*10 << endl;

	return 0;
}