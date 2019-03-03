#include <iostream>
#include <cassert>
/*
assert는 릴리즈 모드에서 하면 안 먹힌드아아아아!! !! !!!!!
*/
using namespace std;

int main()
{
	int score;
	while (true)
	{
		cin >> score;
		
		assert(score >= 0);
		cout << "=> score : " << score << endl;
	}

	return 0;
}