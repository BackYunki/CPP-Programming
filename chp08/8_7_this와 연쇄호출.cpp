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
//	s1.setID(2); //Simple::setID(&s1, 1); 문법상 안 되지만, 사실 이렇게 함수리스트가 작성되어 있고 거기에 
//	s2.setID(4); // 포인터가 내부적으로 들어가서 호출되는 것임! 매번 같은 함수 만들 순 없기 때문이야~
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