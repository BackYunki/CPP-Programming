#include <iostream>
#include <string>
#include <vector>
#include <utility>

enum class Colors
{
	RED = 1,
	GREEN,
	BLUE
};

void printColorName(Colors color)
{
	switch (color)
	{
	case Colors::RED:
		std::cout << "»¡°£»ö ÆÒÆ¼¸¦ ÀÔÀ¸¼Ì±º¿ä?\n";
		break;
	case Colors::GREEN:
		std::cout << "ÃÊ·Ï»ö ÆÒÆ¼¸¦ ÀÔÀ¸¼Ì±º¿ä?\n";
		break;
	case Colors::BLUE:
		std::cout << "ÆÄ¶õ»ö ÆÒÆ¼¸¦ ÀÔÀ¸¼Ì±º¿ä?\n";
		break;
	}
}

void printColorName2(Colors color)
{
	switch (static_cast<int>(color))
	{
	case 1:
		std::cout << "»¡°£»ö ÆÒÆ¼¸¦ ÀÔÀ¸¼Ì±º¿ä?\n";
		break;
	case 2:
		std::cout << "ÃÊ·Ï»ö ÆÒÆ¼¸¦ ÀÔÀ¸¼Ì±º¿ä?\n";
		break;
	case 3:
		std::cout << "ÆÄ¶õ»ö ÆÒÆ¼¸¦ ÀÔÀ¸¼Ì±º¿ä?\n";
		break;
	}
}

void printColorName3(int select, Colors& Panty)
{
	Panty = static_cast<Colors>(select);
	printColorName(Panty);
}

int main()
{
	using namespace std;

	Colors Panty = Colors::RED;
	
	//printColorName(Panty);
	//printColorName2(Panty);

	int select = 0;

	cout << "¾î¶² »ö±ò·Î °í¸£½Ã°Ú½À´Ï±î?\n";
	cout << "1. »¡°­»ö\n2. ÃÊ·Ï»ö\n3. ÆÄ¶û»ö\n\n";
	cout << ">> ";
	cin >> select;
	
	printColorName3(select, Panty);

	return 0;
}