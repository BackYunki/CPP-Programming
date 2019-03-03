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
		std::cout << "������ ��Ƽ�� �����̱���?\n";
		break;
	case Colors::GREEN:
		std::cout << "�ʷϻ� ��Ƽ�� �����̱���?\n";
		break;
	case Colors::BLUE:
		std::cout << "�Ķ��� ��Ƽ�� �����̱���?\n";
		break;
	}
}

void printColorName2(Colors color)
{
	switch (static_cast<int>(color))
	{
	case 1:
		std::cout << "������ ��Ƽ�� �����̱���?\n";
		break;
	case 2:
		std::cout << "�ʷϻ� ��Ƽ�� �����̱���?\n";
		break;
	case 3:
		std::cout << "�Ķ��� ��Ƽ�� �����̱���?\n";
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

	cout << "� ����� ���ðڽ��ϱ�?\n";
	cout << "1. ������\n2. �ʷϻ�\n3. �Ķ���\n\n";
	cout << ">> ";
	cin >> select;
	
	printColorName3(select, Panty);

	return 0;
}