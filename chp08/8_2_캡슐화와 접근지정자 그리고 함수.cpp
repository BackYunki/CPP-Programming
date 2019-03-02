#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <string>
using namespace std;

class Date
{
private:
	int _month;
	int _day;
	int _year;

public:
	Date()
	{

	}
	Date(int _month, int _day, int _year)
	{
		this->_month = _month;
		this->_day = _day;
		this->_year = _year;
	}
	~Date() {}

	void copyFrom(const Date& origin)
	{
		_month = origin._month;
		_day = origin._day;
		_year = origin._year;
	}

	void setDate(const int& month_input, const int& day_input, const int& year_input)
	{
		this->_month = month_input;
		this->_day = day_input;
		this->_year = year_input;
	}

	void setMonth(const int& month_input)
	{
		this->_month = month_input;
	}

	const int& getDay()
	{
		return _day;
	}
};

int main()
{
	Date today;
	today.setDate(11, 29, 2018);
	today.setMonth(12);
	cout << today.getDay() << endl;
	
	Date copy;
	copy.copyFrom(today);

	return 0;
}