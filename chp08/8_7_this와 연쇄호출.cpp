#include "Calc.h"

class Simple
{
private:
	int m_id;
public:
	Simple(int id)
	{
		using namespace std;
		setID(id);

		cout << this << endl;
	}
	void setID(int id) { m_id = id; }
	int  getID() { return m_id; }
};

//int main()
//{
//	Simple s1(1), s2(2);
//	s1.setID(2); //Simple::setID(&s1, 1); ������ �� ������, ��� �̷��� �Լ�����Ʈ�� �ۼ��Ǿ� �ְ� �ű⿡ 
//	s2.setID(4); // �����Ͱ� ���������� ���� ȣ��Ǵ� ����! �Ź� ���� �Լ� ���� �� ���� �����̾�~
//
//	cout << &s1 << " " << &s2 << endl;
//	return 0;
//}

int main()
{
	Calc cal(10);
	//cal.add(10);
	//cal.sub(10);
	//cal.mult(2);
	//cal.print();
	cal.add(10).mult(2).sub(2).print();
}