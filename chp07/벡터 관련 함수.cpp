#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v{ 1,2,3 };
	// v.reserve(1024);
	// reserve �� ���� ������ �̸� �Ҵ��صּ� ��, ����Ʈ�� Ȯ���� ���� �ȿ��� ���� �� �� �� �־� �ӵ��� �����Ѵ�.

	// ����Ÿ �Լ��� ���� �ּҸ� �޾ƿͼ� �����ͷ� ������ �� �ִ�.
	// int *ptr = v.data();

	v.resize(2);
	for (auto& e : v)
	{
		cout << e << ' ';
	}
	cout << '\n';
	cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;
	//�뷮�� 3�ε�. ���� v[2] ���ʹ� ������ ���Ƴ���. �����ͷ� �����غ���.
	int* ptr = v.data();
	cout << ptr[2] << endl;
	//������� ���� �� �ִ� ���̶�� ���� �� �� �ִ�!
	return 0;
}