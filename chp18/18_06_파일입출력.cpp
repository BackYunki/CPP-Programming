#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit() 함수용
#include <sstream>

using namespace std;

int main()
{
	// writing : 아스키로 저장하는 것은 느리다. 일반적으로 바이너리로 함.
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

		//const unsigned num_data = 10; // 데이터가 몇개 있는 지 확인하는 용
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
		// 영역을 벗어나면서 소멸자가 스트림 알아서 닫는다.
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