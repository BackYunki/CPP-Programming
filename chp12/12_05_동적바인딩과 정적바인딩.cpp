#include <iostream>
using namespace std;

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int main()
{
	int x, y;
	cout << "x: "; cin >> x;
	cout << "y: "; cin >> y;
	
	int op;
	cout << "\n0: add\n1: subtract\n2: multiply\n";
	cin >> op;

	// static binding(early binding) : ������ Ÿ�ӿ� �Ҵ��� �� �� ��.
	int result = 0;
	switch (op)
	{
	case 0: result = add(x, y); break;
	case 1: result = subtract(x, y); break;
	case 2: result = multiply(x, y); break;
	}
	cout << result << '\n';

	// dynamic binding(late binding) : ����ð��� �޸�(�ּ�) ������ �Ͼ�� ��
	int(*func_ptr)(int, int) = nullptr;
	switch (op)
	{
	case 0: func_ptr = add; break;
	case 1: func_ptr = subtract; break;
	case 2: func_ptr = multiply; break;
	}
	
	cout << func_ptr(x, y) << endl;

	return 0;
}