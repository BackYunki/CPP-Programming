#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <algorithm>
#include <fstream>

using namespace std;

class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(const double &x = 0.0, const double &y = 0.0, const double &z = 0.0)
		: m_x(x), m_y(y), m_z(z) {}

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }

	Point& operator + (const Point& rhs)
	{
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		m_z += rhs.m_z;
		
		return *this;
	}

	friend ostream& operator << (ostream& out, const Point& point)
	{
		out << point.m_x << ' ' << point.m_y << ' ' << point.m_z;
		return out;
	}

	friend istream& operator >> (istream& in, Point& point)
	{
		cout << "Enter x,y,z\n";
		in >> point.m_x >> point.m_y >> point.m_z;
		//in.ignore(32474, '\n');
		return in;
	}
};

int main()
{
	ofstream of("out.txt");

	//Point p1(1, 2, 3), p2(2,3,4);
	//cout << (Point(1, 2, 3) + Point(2, 3, 4)) << endl;
	//cout << p1 << endl << p2 << endl;
	//
	//of << p1 << endl << p2 << endl;

	Point p1, p2;
	cin >> p1 >> p2;

	of << p1 << endl << p2 << endl;
	of << "Sum = " << (p1 + p2) << endl;
	of.close();

	ifstream ifs("out.txt");
	Point p3, p4;
	ifs >> p3 >> p4;
	cout << p3 << endl << p4 << endl;

	ifs.close();

	return 0;
}