#include <iostream>
#include <regex>
using namespace std;

int main()
{
	// 숫자인지 판별하는 것.
	// + : 1개 이상의 글자다.
	// * : 입력을 안 받아도 괜찮다.
	//regex re("\\d+");
	//regex re("[ab]");
	//regex re("[[:digit:]]{3}"); // {개수} : 개수 만큼 딱 맞춰서 입력받아야만 한다. 이 경우는 0~9까지의 숫자 3개
	//regex re("[A-Z]{1,5}");
	regex re("([0-9]{1})([-]?)([0-9]{1,4})");
	string str;

	while (true)
	{
		getline(cin, str);

		if (regex_match(str, re))
			cout << "Match\n";
		else
			cout << "No Match\n";
		
		// print matches
		{
			auto begin = sregex_iterator(str.begin(), str.end(), re);
			auto end = sregex_iterator();
			for (auto itr = begin; itr != end; ++itr)
			{
				smatch match = *itr;
				cout << match.str() << " ";
			} cout << '\n';
		} cout << '\n';

	}

	return 0;
}