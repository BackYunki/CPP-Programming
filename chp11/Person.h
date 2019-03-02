#pragma once

#include <string>
#include <iostream>

class Person
{
private:
	std::string m_name;

public:
	Person(const std::string & name_in = "No Name")
		: m_name(name_in) {}
};