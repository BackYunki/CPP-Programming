#include <iostream>
#include <string>
using namespace std;

int add(int x, int y)
{
	return x + y;
}

// ���ϰ��� �ٸ��ٰ� �����ε��� �Ǵ� �� �ƴϴ�.
//double add(int x, int y)
//{
//	return x + y;
//}

double add(int x, int y, int z)
{
	return x + y + z;
}

// �����ε��� ��ȣ��
void print(float value)
{
	cout << value << endl;
}

void print(size_t value)
{
	cout << value << endl;
}

int main()
{
	//print(3.14);
	//print(10);

	print(3.14f);
	print(10u);
	
	return 0;
}