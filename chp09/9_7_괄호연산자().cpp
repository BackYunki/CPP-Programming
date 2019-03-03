#include <iostream>

using namespace std;

class Accumulator
{
private:
	int m_counter = 0;

// Functor ��� �ϴµ�. ��ġ �Լ��� ȣ���ϴ� �Ͱ��� ȿ���� ��.
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