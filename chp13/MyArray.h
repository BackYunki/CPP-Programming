#pragma once
#include <iostream>
#include <cassert>

template <typename T, unsigned int SIZE_T>
class MyArray
{
private:
	T *m_data;

public:
	MyArray()
	{
		m_data = new T[SIZE_T];
	}

	~MyArray()
	{
		reset();
	}

	void reset()
	{
		if (m_data != nullptr) delete[] m_data;
		m_data = nullptr;
	}

	T & operator[] (int index)
	{
		assert(index >= 0 && index < SIZE_T);
		return m_data[index];
	}

	unsigned int getLength()
	{
		return SIZE_T;
	}

	void print()
	{
		for (int i = 0; i < SIZE_T; i++)
			std::cout << m_data[i] << ' ';
		std::putchar('\n');
	}
};
