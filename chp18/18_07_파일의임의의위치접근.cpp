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
		ifs.seekg(5); // 파일의 처음부터 5바이트 이동한 다음에 읽어들여라. 즉 abcde 이동하고 f부터 읽는다는 뜻
		// seekg(5, ios::beg); 는 begin 의 줄임말로 파일의 시작부터 5바이트다.
		cout << (char)ifs.get() << endl; 

		ifs.seekg(5, ios::cur); // 현재 커서의 위치 이후부터(읽은 뒤) 5바이트 뒤로 이동한 곳부터 읽어라. fghij k를 읽겠지?
		cout << (char)ifs.get() << "읽은 바이트 수 : " << ifs.tellg() << endl;
		

		ifs.seekg(-5, ios::end);  // \n이 사실 \rf\cr 라인피드 캐리지 리턴이라서 2문자인 것 같다. 그래서 x가 읽히는듯..?
		cout << (char)ifs.get() << endl;

		ifs.seekg(0, ios::end); // 0은 마지막을 의미
		cout << ifs.tellg() << endl;
	}
}