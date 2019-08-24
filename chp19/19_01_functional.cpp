#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void goodbye(const string& s)
{
	cout << "Goodbye " << s << endl;
}

class Object
{
public:
	int m_id;
	Object(int id) : m_id(id) {}
	void hello(const string& s)
	{
		cout << "Hello " << s << ", id: " << m_id <<endl;
	}
};

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	auto func2 = [](int val) {cout << val << endl; };
	for_each(v.begin(), v.end(), func2);
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });
	function<void(int)> func3 = func2;
	func3(123);

	function<void()> func4 = bind(func3, 456);
	func4();

	{
		Object instance(5);
		auto f = bind(&Object::hello, &instance, placeholders::_1);
		f("World");

		auto f2 = bind(&goodbye, placeholders::_1);
		f2("yunki");
	}

	return 0;
}