#include <iostream>
#include <regex>
using namespace std;

int main()
{
	// �������� �Ǻ��ϴ� ��.
	// + : 1�� �̻��� ���ڴ�.
	// * : �Է��� �� �޾Ƶ� ������.
	//regex re("\\d+");
	//regex re("[ab]");
	//regex re("[[:digit:]]{3}"); // {����} : ���� ��ŭ �� ���缭 �Է¹޾ƾ߸� �Ѵ�. �� ���� 0~9������ ���� 3��
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