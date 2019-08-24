#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit() �Լ���
#include <sstream>

using namespace std;

int main()
{
	// writing : �ƽ�Ű�� �����ϴ� ���� ������. �Ϲ������� ���̳ʸ��� ��.
	if (true)
	{
		ofstream ofs("my_first_file.dat"); // ios::app, ios::binary
		// ofs.open("my_first_file.dat");

		if (!ofs)
		{
			cerr << "Couldn't open file.\n";
			exit(1);
		}

		//ofs << "Line1\n";
		//ofs << "Line2\n";

		//const unsigned num_data = 10; // �����Ͱ� � �ִ� �� Ȯ���ϴ� ��
		//ofs.write((char*)&num_data, sizeof(num_data));

		//for (int i = 0; i < num_data; i++)
		//{
		//	ofs.write((char*) &i, sizeof(i));
		//}

		stringstream ss;
		ss << "Line 1" << endl;
		ss << "Line 2" << endl;
		string str = ss.str();

		unsigned str_length = str.size();
		ofs.write((char*)& str_length, sizeof(str_length));
		ofs.write(str.c_str(), str_length);
		// ������ ����鼭 �Ҹ��ڰ� ��Ʈ�� �˾Ƽ� �ݴ´�.
	}

	if (true)
	{
		ifstream ifs("my_first_file.dat");

		if (!ifs)
		{
			cerr << "Cannot open file.\n";
			exit(1);
		}

		/*while (ifs)
		{
			string str;
			getline(ifs, str);
			cout << str << endl;
		}*/

	/*	unsigned num_data = 0;
		ifs.read((char*)&num_data, sizeof(num_data));

		cout << num_data << endl;

		for (unsigned i = 0; i < num_data; i++)
		{
			int num;
			ifs.read((char*)&num, sizeof(num));

			cout << num << endl;
		}*/

		unsigned str_len = 0;
		ifs.read((char*)& str_len, sizeof(str_len));
		string str;
		str.resize(str_len);
		ifs.read(&str[0], str_len);

		cout << str << endl;
	}


	return 0;
}