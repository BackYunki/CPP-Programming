#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;

class IntArray
{
private:
	unsigned m_size = 0U;
	int *m_data = nullptr;

public:
	IntArray(const unsigned& length)
		: m_size(length)
	{
		m_data = new int[m_size];
	}	
	IntArray(const initializer_list<int>& list) 
		: IntArray(list.size())	// 내가 실수했던게 m_length(list.size()) 로 했던건데.
								// 이건 아직 공간 할당이 안 된 상태라서 쓸 수 없어~
	{
		int cnt = 0;

		for (const auto& e : list)
			m_data[cnt++] = e;
	}

	IntArray& operator = (const IntArray &rhs)
	{
		cout << "Assign Operator Called.\n";

		if (this == &rhs) return *this;
		delete[] m_data;

		m_size = rhs.m_size;

		if (rhs.m_data != nullptr)
		{
			//m_data = new int[m_length];
			IntArray(rhs.m_size);
			for (unsigned i = 0; i < m_size; ++i)
				m_data[i] = rhs.m_data[i];
		}

		else
		{
			cout << "Memory Allocation Failed!\n";
			m_data = nullptr;
			exit(1);
		}

		return *this;
	}

	friend ostream& operator << (ostream& out, const IntArray& rhs)
	{
		for (unsigned i = 0; i < rhs.m_size; i++)
		{
			out << rhs.m_data[i] << ' ';
		}
		out << '\n';

		return out;
	}

	~IntArray()
	{
		delete[] this->m_data;
	}
};

int main()
{
	int my_arr1[5]{ 1,2,3,4,5 };
	int *my_arr2 = new int[5]{ 1,2,3,4,5 };

	auto il = { 10, 20, 30 };

	IntArray int_array { 1,2,3,4,5 };
	cout << int_array << endl;
	cout << '\n';
	int_array = IntArray{ 1,2,3,4,5,6 };
	cout << int_array << endl;

	int_array = int_array;

	delete[] my_arr2;

	return 0;
}