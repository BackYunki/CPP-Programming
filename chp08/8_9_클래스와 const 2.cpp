#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>
using namespace std;

class Something
{
public:
	string s_value = "default";

	const string& getValue() const { return s_value; }	// 객체가 상수화 되어버리면 이걸로 자동으로 찾아감
	      string& getValue()	   { return s_value; }
};

int main()
{
	Something something;
	something.getValue();
	// something.getValue() = "yunki"; 이건 그냥 레퍼런스가 와서 수정도 가능해!

	const Something something2;
	something2.getValue();
	// something.getValue() = "yunki"; 상수 레퍼런스가 와서 값을 바꿀 수 없어!

	return 0;
}