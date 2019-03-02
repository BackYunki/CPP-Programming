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

	const char* str01 = "문자 수정은 불가";
	str01 = "하지만 새로운 문자열로 대체는 가능";
	
	const string str02("const면 전 못 바꿉니다.");
	const string temp("저로 바꿔주세요.");
	//str02 = temp;

	return 0;
}