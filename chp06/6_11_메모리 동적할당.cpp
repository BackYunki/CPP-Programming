#include <iostream>

int main()
{
	using namespace std;

	//// uniform initializer �� �غ���
	//int *ptr = new (std::nothrow) int{ 1 };	// nothrow �� ����ϸ� �Ҵ� �� ������ nullptr�� ����.
	//										// ���α׷��� �״� �ͺ��� ������.
	//if (ptr != nullptr)
	//{
	//	cout << *ptr << endl;
	//}
	//else
	//{
	//	cout << "�޸𸮸� �Ҵ� ���� �� �߽��ϴ�.\n";
	//}
	//delete ptr;

	// ������ ��
	while (true)
	{
		int *temp = new int;
		cout << temp << endl;
		delete temp;	// <- ��� �� ���ָ� �޸� �Ҵ� ��� �ż� ���߿� �� �������� ����
	}

	return 0;
}