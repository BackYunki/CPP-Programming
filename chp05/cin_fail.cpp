#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	string first;
	cout << "Enter your first name >> ";
	cin >> first;

	string last;
	cout << "Enter your last name >> ";
	cin >> last;

	int num1 = 0;
	cout << "Enter an integer >> ";
	cin >> num1;
	if (cin.fail())
	{
		cout << "범위를 초과했습니다.\n";
	}

	char op = 0;
	cout << "Enter an Operator >> ";
	cin >> op;

	int num2 = 0;
	cout << "Enter an integer >> ";
	cin >> num2;

	double result = 0.f;
	switch (op)
	{
	case '+': result = num1 + num2; break;
	case '-': result = num1 - num2; break;
	case '*': result = num1 * num2; break;
	case '/': result = num1 / num2; break;
	default: break;
	}
	cout << result << endl;
	
	return 0;
}