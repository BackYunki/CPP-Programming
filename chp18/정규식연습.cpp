#include <string>
#include <iostream>
#include <regex>
using namespace std;

int main()
{
	//regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	//string str;

	//while (true)
	//{
	//	cout << "Email >> ";
	//	getline(cin, str);
	//
	//	if (regex_match(str, pattern))
	//	{
	//		cout << "\nMatch!\n";
	//	}
	//	else
	//	{
	//		cout << "\nNo Match!\n";
	//	}
	//}

	//string a = "GeeksForGeeks";
	//regex b("(Geek)(.*)");
	////regex b("(.*)([.])(html|HTML)");
	//if (regex_match(a, b))
	//	cout << "Matched!\n";

	//auto begin = sregex_iterator(a.begin(), a.end(), b);
	//auto end = sregex_iterator();

	//for (auto iter = begin; iter != end; ++iter)
	//{
	//	smatch match = *iter;
	//	cout << match.str() << " ";
	//} cout << '\n';
	/*regex re("([\\w]([-_\\.]?[\\w]){6,12})@([\\w]([-_\\.]?[\\w])*[.][a-zA-Z]{2,3})");*/
	regex re("(^[\\w\\._%\\+-]+@[\\w\\.-]+\\.[a-z]{2,}$)");
	while (true)
	{
		string email;
		getline(cin, email);
		if (regex_match(email, re))
		{
			cout << "Matched!\n";
		}
		else
		{
			cout << "No Matched!\n";
		}
	}

	return 0;
}