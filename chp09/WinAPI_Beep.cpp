#include <iostream>
#include <Windows.h>
#include <map>
using namespace std;

double root = 261.6;	// ����(261.6 hz = C4(���� ��))
char keyList[]{ 'a', 'w', 's', 'e', 'd', 'f',
                't', 'g', 'y', 'h', 'u', 'j', 'k' }; // �ǹݼ���: a = ��, w = ��# , s = �� ...
map<char, double> table;	// Ű�� ���ļ��� ��� ��

// Ű-���ļ� �� ���� : 
// ��Ÿ�긦 �ٲٰ� �Ǹ� �������ļֶ�õ��� ���ļ��� 2�� �Ǵ� �������� �ٲ�� ������. 
// ���̺��� �����ؾ��մϴ�. 
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

// z,x Ű�� ��Ÿ�긦 �ø��ų� ���� �� �ֽ��ϴ�.
// �ٲ� �Ŀ� Ű-���ļ� ���̺��� ������Ʈ �մϴ�.
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
	updateTable();	// ���ʿ� c4�� �߽����� ���踦 ����ϴ�.

	char key;
	while (true)
	{
		cin >> key;
		// z ��Ÿ�� ������, x ��Ÿ�� �ø���
		if (key == 'z' || key == 'x')
		{
			changeOctave(key);
			continue;
		}
		// key�� �����ϴ� ���ļ��� �����ɴϴ�. 
		DWORD frequency = (DWORD)table.find(key)->second;
		Beep(frequency, 500);
	}
	
	return 0;
}