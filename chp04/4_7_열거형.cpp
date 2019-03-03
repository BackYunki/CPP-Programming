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

	// 굳이 이렇게 할 필요가 있나? State myState = HAPPY; 로 할듯
	State myState = static_cast<State>(-1);

	return 0;
}