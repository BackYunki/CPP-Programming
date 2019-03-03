#pragma once
template<class T>
class Storage8
{
private:
	T m_array[8];

public:
	void set(int index, const T & value)
	{
		m_array[index] = value;
	}

	const T& get(int index)
	{
		return m_array[index];
	}
};

// 탬플릿으로 코드는 길어졌지만, 메모리 할당량은 줄일 수 있게 되었다.
template<>
class Storage8<bool>// c++에서 bool 타입은 1바이트다. 8bit징
{
private:
	unsigned char m_data;	// 1바이트당

public:
	void set(int index, bool value)
	{
		unsigned char mask = 1 << index;

		if (value) // true 로 할 건지
		{
			m_data |= mask;
		}
		else // false로 할 건지
		{
			m_data &= ~mask;
		}
	}

	bool get(int index)
	{
		unsigned char mask = 1 << index;
		return (m_data & mask) != 0;	// 있으면 0보단 크니까 0이 아니라고 한 것임.
	}
};