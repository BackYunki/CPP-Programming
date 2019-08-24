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

	// 람다식은 익명으로 간단히 쓰고 싶을 때 유용하다.
	[](const int& i) -> void {cout << "Hello, World! " << i << "\n" ; } (1234);
	for (int i = 1; i <= 10; i++)
	{
		[](const int& i) -> void {cout << "i : " << i << '\n'; }(i);
	}
	{
		string name = "JackJack";
		// introduce ([요거]) 안에 &를 통해 스코프 안에 있는
		// 변수들을 참조할 수 있다.
		// = 를 쓸 경우는 copy 로 가져온다.
		// &name 이런식으로 쓰면 name만, &하나만 쓰면
		// 스코프 안에 있는 모든 변수를 참조할 수 있음.
		[&]() {cout << name << endl; }();
	}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	// ->type 은 void 일 때 생략해도 되는 것 같다.
	/*auto func2 = [](int val) {cout << val << endl; };
	for_each(v.begin(), v.end(), func2);*/
	// 위에처럼 쓰면 좀 그렇고,, 아래처럼 익명으로 써~
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

	cout << []()->int {return 1; }() << endl;

	return 0;
}