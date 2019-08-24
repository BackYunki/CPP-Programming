#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	auto func = [](const int& i) -> void { cout << "Hello, World!, " << i << endl; };
	func(123);

	// ���ٽ��� �͸����� ������ ���� ���� �� �����ϴ�.
	[](const int& i) -> void {cout << "Hello, World! " << i << "\n" ; } (1234);
	for (int i = 1; i <= 10; i++)
	{
		[](const int& i) -> void {cout << "i : " << i << '\n'; }(i);
	}
	{
		string name = "JackJack";
		// introduce ([���]) �ȿ� &�� ���� ������ �ȿ� �ִ�
		// �������� ������ �� �ִ�.
		// = �� �� ���� copy �� �����´�.
		// &name �̷������� ���� name��, &�ϳ��� ����
		// ������ �ȿ� �ִ� ��� ������ ������ �� ����.
		[&]() {cout << name << endl; }();
	}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	// ->type �� void �� �� �����ص� �Ǵ� �� ����.
	/*auto func2 = [](int val) {cout << val << endl; };
	for_each(v.begin(), v.end(), func2);*/
	// ����ó�� ���� �� �׷���,, �Ʒ�ó�� �͸����� ��~
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

	cout << []()->int {return 1; }() << endl;

	return 0;
}