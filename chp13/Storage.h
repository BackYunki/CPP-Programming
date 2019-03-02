#pragma once

#include <iostream>
// double 타입의 경우엔 scientific notation 을 하고싶다.
template<class T>
class Storage
{
private:
	T m_value;
public:
	Storage(T value)
	{
		m_value = value;
	}
	~Storage()
	{
	}

	void print()
	{
		std::cout << m_value << '\n';
	}
};

template<>
void Storage<double>::print()
{
	std::cout << "Double Type ";
	std::cout << std::scientific << m_value << '\n';
}