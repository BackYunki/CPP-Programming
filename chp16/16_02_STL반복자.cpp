#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	/*vector<int> container;
	for (int i = 0; i < 10; i++)
	{
		container.push_back(i);
	}

	vector<int>::const_iterator iter;
	iter = container.begin();
	while (iter != container.end())
	{
		cout << *iter << " ";
		++iter;
	}
	cout << endl;

	for (const auto& e : container)
	{
		cout << e << ' ';
	} cout << '\n';*/

	{
		list<int> container;
		for (int i = 0; i < 10; i++)
		{
			container.push_back(i);
		}

		container.reverse();
		container.sort();

		for (auto& e : container)
		{
			cout << e << ' ';
		} cout << "\n";
	}

	/*{
		map<int, char> container;
		for (int i = 0; i < 26; i++)
		{
			container.insert(make_pair(i, i+'a'));
		}

		for (const auto& entry : container)
		{
			cout << entry.first << ":" << entry.second << '\n';
		}
	}*/

	return 0;
}