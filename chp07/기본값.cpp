#include <iostream>
#include <string>	
using namespace std;

//�⺻���� �ִ� ��쿡�� ������Ͽ� �̷��� �صδ� �� ����.
void print(int x = 10, int y = 20, int z = 30);

void print(int x, int y, int z) {}

// �� ��� ambiguous �ϴ�.
// print(10) �� ��� �Ʒ����� y�� ������ �Ŷ� y�� 10�� �� ���� �ֱ� �����̴�.
// ���� ����Ʈ ���� �Լ� �����ε��ϴµ� ������ �ش�.
void print(int x) {}
void print(int x, int y = 10) {}

int main()
{
	//print(10);	

	return 0;
}