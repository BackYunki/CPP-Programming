#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	const string filename = "my_file.txt";

	// make a file
	{
		ofstream ofs(filename);
		for (char i = 'a'; i <= 'z'; i++)
		{
			ofs << i;
		}
		ofs << endl;
	}

	// read the file
	{
		ifstream ifs("my_file.txt");
		ifs.seekg(5); // ������ ó������ 5����Ʈ �̵��� ������ �о�鿩��. �� abcde �̵��ϰ� f���� �д´ٴ� ��
		// seekg(5, ios::beg); �� begin �� ���Ӹ��� ������ ���ۺ��� 5����Ʈ��.
		cout << (char)ifs.get() << endl; 

		ifs.seekg(5, ios::cur); // ���� Ŀ���� ��ġ ���ĺ���(���� ��) 5����Ʈ �ڷ� �̵��� ������ �о��. fghij k�� �а���?
		cout << (char)ifs.get() << "���� ����Ʈ �� : " << ifs.tellg() << endl;
		

		ifs.seekg(-5, ios::end);  // \n�� ��� \rf\cr �����ǵ� ĳ���� �����̶� 2������ �� ����. �׷��� x�� �����µ�..?
		cout << (char)ifs.get() << endl;

		ifs.seekg(0, ios::end); // 0�� �������� �ǹ�
		cout << ifs.tellg() << endl;
	}
}