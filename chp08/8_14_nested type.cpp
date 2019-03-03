#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>
using namespace std;

class Fruit
{
public:
	enum class FruitType
	{
		APPLE, BANANA, CHERRY,
	};

	FruitType m_type;

public:
	Fruit(const FruitType& type) : m_type(type) {}

	FruitType getType() { return m_type; }
};

int main()
{
	Fruit apple(Fruit::FruitType::APPLE);

	if (apple.getType() == Fruit::FruitType::APPLE)
		cout << "Apple\n";

	return 0;
}