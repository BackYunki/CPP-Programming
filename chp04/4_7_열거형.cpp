#include <iostream>
#include <string>

enum State
{
	HAPPY = -1,
	SAD,
	EXITED
};

int main()
{
	using namespace std;
	int input = 0;

	// ���� �̷��� �� �ʿ䰡 �ֳ�? State myState = HAPPY; �� �ҵ�
	State myState = static_cast<State>(-1);

	return 0;
}