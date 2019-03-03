#define INITIALIZER_TEST 0 
#define FUNCTION_TEST 1
#include <iostream>
#include <cassert>
#include <initializer_list>
using namespace std;

class IntArray
{
private:
	unsigned int m_size		= 0U;
	unsigned int m_capacity = 0U;
			 int * m_data	= nullptr;

public:
	// 1-1. normal ctor
	IntArray(const unsigned int & size = 1) : m_capacity(size)
	{
		assert(size > 0);
		// 사이즈 짝수: 여분 용량 +2; 홀수: 여분 용량 +1; => 이러면 인덱스가 항상 짝수여서 계산도 편리함
		if (size % 2 == 0) m_capacity += 2;
		else m_capacity += 1;

		m_data = new int[m_capacity];
		m_size = 0;
		if (m_data == nullptr)
		{
			cout << "memory allocation failed.\n";
			exit(1);
		}
	}
	// 1-2. initializer_list ctor
	IntArray(const initializer_list<int> & list) : IntArray(list.size())
	{
		m_size = list.size();
		
		int cnt = 0;
		for (const auto & e : list)
		{
			m_data[cnt++] = e;
		}
	}
	// 1-3. copy ctor
	IntArray(const IntArray & origin)
	{
		// delete obsolete data.
		delete[] this->m_data;
		// and reallocate with size of origin.
		//m_data = new int[origin.m_size];
		if (origin.m_data != nullptr)
		{
			m_size = origin.m_size;
			m_capacity = origin.m_capacity;
			m_data = new int[origin.m_size];
		}
		else
		{
			cout << "Assign Operatoration failed.\n";
			this->m_data = nullptr;
			exit(1);
		}
		// finally, copy the values.
		for (unsigned int i = 0; i < origin.m_size; ++i)
			m_data[i] = origin.m_data[i];
	}
	// 1-4. dtor
	~IntArray()
	{
		delete[] this->m_data;
	}

	// 2-1. return size and capacity. 
	unsigned int size()		{ return m_size; }
	unsigned int capacity() { return m_capacity; }
	// 2-2. check container state. 
	bool isEmpty()	{ return m_size == 0 ? true : false; }
	bool isFull()	{ return m_capacity == m_size ? true : false; }
	
	// 3. return front or back element.
	int& front() 
	{
		if (isEmpty()) { cout << "list is empty!\n"; assert(!isEmpty()); }
		return m_data[0];
	}
	int& back()
	{
		if (isEmpty()) { cout << "list is empty!\n"; assert(!isEmpty()); }
		return m_data[m_size - 1];
	}

	// 4-1. push back element and memory optimization.
	void push_back(const int & element)
	{
		if (isFull() && !upAlloc())
		{
			cout << "Upscaling memory allocation failed.\n";
			return;
		}

		m_data[m_size++] = element;
	}
	// 4-2. pop back element and memory optimization.
	void pop_back()
	{
		if (isEmpty())
		{
			cout << "list is empty.\n";
			assert(!isEmpty());
			return;
		}
		else if (m_size - 1 == m_capacity / 2)
		{
			if (!downAlloc())
			{
				cout << "DownScaling memory allocation failed.\n";
			}
		}

		m_size--;
	}

	// 5-1. double the capacity of the array.
	bool upAlloc()
	{
		m_capacity *= 2;
		int * temp_data = new int[m_capacity];
		if (temp_data == nullptr) return false;

		for (unsigned int i = 0; i < m_size; ++i)
			temp_data[i] = m_data[i];

		delete[] this->m_data;
		m_data = temp_data;

		return true;
	}
	// 5-2. decrease the array capacity.
	bool downAlloc()
	{
		// 용량이 짝수였으면 절반크기 + 2만큼, 홀수였으면 절반크기 + 1로 무조건 용량을 짝수로 만듦
		if ((m_capacity / 2) % 2 == 0)
			m_capacity = (m_capacity / 2) + 2;
		else
			m_capacity = (m_capacity / 2) + 1;

		int * temp_data = new int[m_capacity];
		if (temp_data == nullptr) return false;

		for (unsigned int i = 0; i < m_size - 1; ++i)
			temp_data[i] = m_data[i];

		delete[] this->m_data;
		m_data = temp_data;

		return true;
	}

	// 6-1. '=' operator overloading.
	IntArray& operator = (IntArray & rhs)
	{
		if (this == &rhs) return *this;
		delete[] this->m_data;	

		if (rhs.m_data != nullptr)
		{
			m_capacity = rhs.capacity();
			m_size = rhs.size();

			m_data = new int[rhs.capacity()];

			for (unsigned int i = 0; i < rhs.size(); ++i)
				m_data[i] = rhs.m_data[i];
		}
		else
		{
			cout << "Assign Operatoration failed.\n";
			this->m_data = nullptr;
			exit(1);
		}
		return *this;
	}
	// 6-2. '<<' operator overloading.
	friend ostream& operator << (ostream& out, const IntArray & rhs)
	{
		for (unsigned int i = 0; i < rhs.m_size; ++i)
		{
			out << rhs.m_data[i] << ' ';
		}
		return out;
	}
	// 6-3. '[]' operator overloading.
	int & operator [] (const unsigned int & index)
	{
		assert(index >= 0 && index < m_size);
		return m_data[index];
	}
};

int main()
{
#if INITIALIZER_TEST == 0
	// initializer_list
	IntArray my_array{ 1,2,3,4,5 };
	cout << "Initializer list : " << my_array << endl;

	// copy constructor
	IntArray my_array2(my_array);
	cout << "Copy Constructor : " << my_array2 << endl;
	
	// Assign Operator
	my_array2 = my_array;
	cout << "Assign Operation : " << my_array2 << endl;

#elif FUNCTION_TEST == 1
	IntArray arr(5);
	for (int i = 1; i <= 5; i++)
		arr.push_back(i);
	cout << "Initial State: " << arr << "\tsize(): " << arr.size() << "\tcapacity(): " << arr.capacity() << endl << endl;

	uint32_t size = arr.size();
	for (uint32_t i = 0; i < size; i++)
	{
		cout << i + 1 << "th pop\n";
		arr.pop_back();
		cout << "After State: " << arr << "\tsize(): " << arr.size() << "\tcapacity(): " << arr.capacity() << endl << endl;
	}
#endif
	return 0;
}