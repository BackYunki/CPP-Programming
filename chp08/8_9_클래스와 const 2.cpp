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

	const string& getValue() const { return s_value; }	// ��ü�� ���ȭ �Ǿ������ �̰ɷ� �ڵ����� ã�ư�
	      string& getValue()	   { return s_value; }
};

int main()
{
	Something something;
	something.getValue();
	// something.getValue() = "yunki"; �̰� �׳� ���۷����� �ͼ� ������ ������!

	const Something something2;
	something2.getValue();
	// something.getValue() = "yunki"; ��� ���۷����� �ͼ� ���� �ٲ� �� ����!

	return 0;
}