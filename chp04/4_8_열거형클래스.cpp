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
	
	enum SAMPLE	// �׳� �̳ѵ� ������Ƽ�� ���� ������ �����ϴ�. 
	{
		TASTED = 't',
	};

	if (static_cast<char>(Color::BLUE) == static_cast<char>(Fruit::BANANA))
	{
		cout << "its char value is same.\n";
	}
	
	//�̳� Ŭ������ ���� �ٸ� Ŭ���������� �񱳰� �� �ȴ�.
	//if (Color::RED == Fruit::APPLE)
	if (Color::RED > Color::GREEN)
	{
		cout << "���尡 �׸����� ũ��\n";
	}

	return 0;
}