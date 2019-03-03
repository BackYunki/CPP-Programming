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

// ���ø����� �ڵ�� ���������, �޸� �Ҵ緮�� ���� �� �ְ� �Ǿ���.
template<>
class Storage8<bool>// c++���� bool Ÿ���� 1����Ʈ��. 8bit¡
{
private:
	unsigned char m_data;	// 1����Ʈ��

public:
	void set(int index, bool value)
	{
		unsigned char mask = 1 << index;

		if (value) // true �� �� ����
		{
			m_data |= mask;
		}
		else // false�� �� ����
		{
			m_data &= ~mask;
		}
	}

	bool get(int index)
	{
		unsigned char mask = 1 << index;
		return (m_data & mask) != 0;	// ������ 0���� ũ�ϱ� 0�� �ƴ϶�� �� ����.
	}
};