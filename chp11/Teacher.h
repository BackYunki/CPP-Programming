#pragma once

#include "Person.h"

class Teacher : public Person
{
private:

public:
	Teacher(const std::string & name_in = "No Name")
		: Person(name_in)
	{}

	void setName(const std::string & name_in)
	{
		m_name = name_in;
	}

	std::string getName()
	{
		return m_name;
	}

	friend std::ostream& operator << (std::ostream & out, const Student & rhs)
	{
		out << rhs.m_name;
		return out;
	}
};