#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Cents
{
private:
	int m_cents;
public:
	Cents(const int& cents = 0) : m_cents(cents) {}
	Cents(const Cents& origin) { m_cents = origin.m_cents; }
	int  getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	friend bool operator < (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents < c2.m_cents;
	}

	bool operator == (const Cents rhs) const
	{
		return m_cents == rhs.m_cents ? true : false;
	}

	bool operator ! () const
	{
		return m_cents == 0 ? true : false;
	}

	Cents operator - () const
	{
		return Cents(-m_cents);
	}

	friend Cents operator + (const Cents& lhs, const Cents& rhs)
	{
		return Cents(lhs.m_cents + rhs.m_cents);
	}

	friend ostream& operator << (ostream& out, const Cents& cent)
	{
		out << cent.m_cents;
		return out;
	}
};

int main()
{
	cout << boolalpha;
	cout << (Cents(10) == Cents(10)) << endl;
	cout << (Cents(0) == Cents(10)) << endl;
	
	vector<Cents> arr(20);
	for (size_t i = 0; i < arr.size(); ++i)
		arr[i].getCents() = i;

	std::random_shuffle(begin(arr), end(arr));	// c++17 에선 못 써!
	
	for (const auto& e : arr)
		cout << e << ' ';
	cout << endl;

	sort(begin(arr), end(arr));

	for (const auto& e : arr)
		cout << e << ' ';
	cout << endl;

	return 0;
}