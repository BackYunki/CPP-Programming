#pragma once

#include <iostream>

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) : m_cents(cents) {}

	friend std::ostream& operator << (std::ostream & out, const Cents & rhs)
	{
		out << rhs.m_cents << " cents ";
		return out;
	}
	bool operator > (Cents & rhs)
	{
		return m_cents > rhs.m_cents;
	}
};