#include <iostream>

int main()
{
	using namespace std;

	char ch = 'c';

	cout << (uintptr_t)&ch << endl;	// ch�� ĳ���Ϳ��� ĳ������ �ּҸ� �ִ� ��� ���ڿ��ΰ�
									// ��� �������Ͽ� null ���� ���� ������ �дٺ��� �̻���
									// ���ڰ� ������ ����!!!!!

	return 0;
}