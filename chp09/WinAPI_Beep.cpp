#include <iostream>
#include <Windows.h>
#include <map>
using namespace std;

double root = 261.6;	// 근음(261.6 hz = C4(가온 다))
char keyList[]{ 'a', 'w', 's', 'e', 'd', 'f',
                't', 'g', 'y', 'h', 'u', 'j', 'k' }; // 건반순서: a = 도, w = 도# , s = 레 ...
map<char, double> table;	// 키와 주파수를 담는 맵

// 키-주파수 맵 갱신 : 
// 옥타브를 바꾸게 되면 도레미파솔라시도의 주파수가 2배 또는 절반으로 바뀌기 때문에. 
// 테이블을 갱신해야합니다. 
void updateTable()
{
	cout << "root : " << root << endl;
	table.clear();
	double temp = root;
	for (unsigned int i = 0; i < 13; i++)
	{
		if (i != 0) temp *= 1.059;

		table[keyList[i]] = temp;
	}
}

// z,x 키로 옥타브를 올리거나 내릴 수 있습니다.
// 바꾼 후에 키-주파수 테이블을 업데이트 합니다.
void changeOctave(const char &key)
{
	switch (key)
	{
	case 'z':
		root /= 2; 
		break;
	case 'x':
		root *= 2;
		break;
	}
	updateTable();	
}

int main()
{
	updateTable();	// 최초에 c4를 중심으로 음계를 만듭니다.

	char key;
	while (true)
	{
		cin >> key;
		// z 옥타브 내리기, x 옥타브 올리기
		if (key == 'z' || key == 'x')
		{
			changeOctave(key);
			continue;
		}
		// key에 대응하는 주파수를 가져옵니다. 
		DWORD frequency = (DWORD)table.find(key)->second;
		Beep(frequency, 500);
	}
	
	return 0;
}