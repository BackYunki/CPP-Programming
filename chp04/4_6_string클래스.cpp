#include <iostream>
#include <string>
#include <limits>

int main()
{
	using namespace std;
	int size = std::numeric_limits<std::streamsize>::max();

	cout << "Enter Your Age : ";
	int age;
	cin >> age;
	cin.ignore(size, '\n');
	
	cout << "\nEnter Your Name : ";
	string name;
	getline(cin, name);

	cout << "Info\n";
	cout << name << ": " << age << endl;

	const char* str01 = "���� ������ �Ұ�";
	str01 = "������ ���ο� ���ڿ��� ��ü�� ����";
	
	const string str02("const�� �� �� �ٲߴϴ�.");
	const string temp("���� �ٲ��ּ���.");
	//str02 = temp;

	return 0;
}