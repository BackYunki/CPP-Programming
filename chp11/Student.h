#pragma once

#include "Person.h"

class Student : public Person
{
private:
	int m_intel;	// intelligence;

public:
	Student(const std::string & name_in = "No Name", const int & intel_in = 0)
		: Person(name_in), m_intel(intel_in)
	{}

	void setName(const std::string & name_in)
	{
		m_name = name_in;
	}
	void setIntel(const int & intel_in)
	{
		m_intel = intel_in;
	}

	std::string getName()
	{
		return m_name;
	}
	int getIntel()
	{
		return m_intel;
	}

	friend std::ostream& operator << (std::ostream & out, const Student & rhs)
	{
		out << rhs.m_name << " " << rhs.m_intel;
		return out;
	}
};