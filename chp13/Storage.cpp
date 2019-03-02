#include "Storage.h"

template<>
void Storage<double>::print()
{
	std::cout << "Double Type ";
	std::cout << std::scientific << m_value << '\n';
}

// 요즘 잘 안 쓰고 그냥 헤더에 몰아넣는다고 한다.