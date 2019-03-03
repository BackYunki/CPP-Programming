#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>
using namespace std;

class Something
{
private:
	int s_value;

public:
	Something(const Something &origin)
	{
		this->s_value = origin.s_value;
		cout << "복사 생성자가 호출되었습니다.\n";
	}

	Something(const int& value)
	{
		s_value = value;
		cout << "생성자가 호출됐습니다.\n";
	}
	
	void setValue(const int& value)
	{
		s_value = value;
	}
	int getValue() const	// 객체가 const 가 될거라면 여기에 값이 바뀌지 않을 것임을 const 로 명시해줘야함
	{
		return s_value;
	}
};

void print(const Something &s)	// 이러면 레퍼런스가 넘어가서 복사가 일어나지 않는다.
//void print(Something s) = > 복사 생성자가 호출된다.
{
	cout << "넘어온 인자의 주소: " << (int)&s << endl;
	cout << s.getValue() << endl;
}

int main()
{
	const Something s1(10);
	//s1.setValue(20);
	cout << s1.getValue() << endl;	// 그래야 여기서 쓸 수 있음
	cout << '\n';

	cout << "보내려는 인자의 주소: " << (int)&s1 << endl;
	print(s1);
	return 0;
}