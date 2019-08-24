#pragma once

#include <iostream>

class Resource
{
public:
	int* m_data = nullptr;
	size_t m_length = 0;
public:
	Resource()
	{
		std::cout << "Resource Contstuctor.\n";
	}
	Resource(size_t length)
	{
		std::cout << "Resource Length Constructor.\n";
		m_length = length;
		m_data = new int[m_length];
	}
	Resource(const Resource& rhs)
	{
		std::cout << "Resource Copy Constructor.\n";
		// 길이 주는 생성자 호출
		Resource(rhs.m_length);

		for (size_t i = 0; i < m_length; i++)
		{
			m_data[i] = rhs.m_data[i];
		}
	}
	~Resource()
	{
		std::cout << "Resource Destructor.\n";
		if (m_data != nullptr)
		{
			delete[] m_data;
		}
	}

	Resource& operator = (Resource& rhs)
	{
		std::cout << "Resource Copy Assignment.\n";
		// 자기 자신일 경우 자신을 반환
		if (&rhs == this) { return *this; }
		// 자기 자신의 데이터를 지우고
		if (this->m_data != nullptr) { delete[] m_data; }
		// rhs 의 데이터를 deep copy
		m_length = rhs.m_length;
		m_data = new int[m_length];
		for (size_t i = 0; i < m_length; i++)
		{
			m_data[i] = rhs.m_data[i];
		}
		return *this;
	}

	void print()
	{
		for (size_t i = 0; i < m_length; i++)
		{
			std::cout << m_data[i] << ' ';
		}
		std::cout << "\n";
	}

	void setAll(const int v)
	{
		for (size_t i = 0; i < m_length; i++)
		{
			m_data[i] = v;
		}
	}
};