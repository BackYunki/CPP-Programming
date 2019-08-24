#pragma once
#include <iostream>
#include "Resource.h"
template <class T>
class AutoPtr
{
public:
	T* m_ptr = nullptr;

	AutoPtr(T* ptr = nullptr) : m_ptr(ptr)
	{
	}
	~AutoPtr()
	{
		if (m_ptr != nullptr)
		{
			delete m_ptr;
		}
	}

	// Operator Overloading
	T& operator* () const
	{
		return *m_ptr;
	}

	T* operator-> () const
	{
		return m_ptr;
	}

	// func
	bool isNull() const { return m_ptr == nullptr; }
};