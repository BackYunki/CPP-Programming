#include <iostream>

using namespace std;



int main()
{
	//static const int* arr = (const int[]) { 1, 2, 3, 4, 5 };

	// ���ڿ� ���ͷ��� Ư���� ��޵˴ϴ�. �׸��� ���α׷��� ������ ������ ���̳ʸ��� ������ �˴ϴ�.
	// �׸��� const char* str = "Hello"; �� "Hello"��� ��򰡿� ����Ǿ� �ִ� �͸���
	// �迭�� ����մϴ�. �׸��� �װ��� ù ��° �ּҿ� str �����Ͱ� ����˴ϴ�.
	// ��ġ�� static const �� ���� ����� �ʱ�ȭ�� �� �迭!�� ��쿡�� ���ڿ�ó�� ���Ǹ� �� �� �־��.

	//char* s1 = "hello";
	//char ch = s1[0];
	//char* ch_ptr = &ch;

	//cout << ch_ptr << endl;

	// static const �迭�� ȿ��: ���ڿ� ���ͷ��� ����� ������ ��� ������ �͸� ��ü�� �ƴ�
	// ���� ������ �Ҵ��ϴ� ���Դϴ�.
	// ���ڿ��� ���� ������� ��������� ���� �� �ֽ��ϴ�.
	static const int intstatic[] = { 3, 54, 12, 53 };
	static const char str[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
	const char* str1 = "Hello";
	const char* str2 = "Hello";

	cout << "��Ʈ�� Ǯ���� ������ ���� ������. ���� ���ڿ��̸� ���� �ּҷ� ���� �纻�� �� ����� �Ѵ�.\n";
	cout << (int)str1 << endl;
	cout << (int)str2 << endl;

	cout << str << endl;
	for (const auto& n : intstatic)
	{
		cout << n << ' ';
	}

	return 0;
}