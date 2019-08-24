#pragma once
#include <iostream>

class Resource
{
public:
	int m_data[100];

public:
	Resource()
	{
		std::cout << "Resource::CTOR\n";
	}

	~Resource()
	{
		std::cout << "Resource::DTOR\n";
	}
};