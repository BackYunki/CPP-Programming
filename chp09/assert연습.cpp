#include <iostream>
#include <cassert>
/*
assert�� ������ ��忡�� �ϸ� �� ������ƾƾƾ�!! !! !!!!!
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