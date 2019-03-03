#include <iostream>

int main()
{
	using namespace std;

	enum class Color : char
	{
		RED		= 'r',
		GREEN	= 'g',
		BLUE	= 'b'
	};

	enum class Fruit
	{
		APPLE		= 'a',
		BANANA		= 'b',
		STRAWBERRY	= 's'
	};
	
	enum SAMPLE	// 그냥 이넘도 프리미티브 값은 대입이 가능하다. 
	{
		TASTED = 't',
	};

	if (static_cast<char>(Color::BLUE) == static_cast<char>(Fruit::BANANA))
	{
		cout << "its char value is same.\n";
	}
	
	//이넘 클래스는 서로 다른 클래스끼리는 비교가 안 된다.
	//if (Color::RED == Fruit::APPLE)
	if (Color::RED > Color::GREEN)
	{
		cout << "레드가 그린보다 크다\n";
	}

	return 0;
}