#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date
{
private:
	int m_month;
	int m_day;
	int m_year;

public:
	Date(const int& m_month, const int& m_day, const int& m_year)
	{
		this->m_month = m_month;
		this->m_day = m_day;
		this->m_year = m_year;
	}
	
	void copyFrom(const Date& origin)
	{
		m_month = origin.m_month;
	}

	void setDate(const int& m_month, const int& m_day, const int& m_year)
	{
		this->m_month = m_month;
		this->m_day = m_day;
		this->m_year = m_year;
	}

	
};



int main()
{
	Date tody{ 8, 4, 2025 };


	return 0;
}