#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	const unsigned char op_viewed = 0x01;	// 0000 0001
	const unsigned char op_edited = 0x02; // 0000 0010
	const unsigned char op_liked = 0x04;	// 0000 0100
	const unsigned char op_shared = 0x08;	// 0000 1000
	const unsigned char op_deleted = 0x80;// 1000 0000

	vector<pair<string, const unsigned char>> list;
	list.push_back(make_pair("�����ȸ", op_viewed));
	list.push_back(make_pair("������", op_edited));
	list.push_back(make_pair("���ƿ�", op_liked));
	list.push_back(make_pair("������", op_shared));
	list.push_back(make_pair("������", op_deleted));

	unsigned char my_flags = 0;
	string article = "�¿��� �����";
	bool canLoop = true;

	cout << "���!). ���¿��� �����Ⱑ ����� 300��!\n";
	
	while (!(my_flags & op_deleted) && canLoop)
	{
		size_t select;
		cout << "\n1. ��纸��\n2. �����ϱ�\n3. ���ƿ�\n4. �����ϱ�\n5. �����ϱ�\n6. ������\n";
		cout << ">> ";
		cin >> select;

		switch (select)
		{
		case 1: 
			my_flags |= op_viewed; 
			cout << article << endl; 
			break;
		case 2:
			my_flags |= op_edited;
			cout << "���� �����մϴ�.\n";
			getchar();
			getline(cin, article);
			my_flags &= ~op_viewed;
			break;
		case 3: 
			my_flags ^= op_liked; 
			if (my_flags & op_liked)
				cout << "�� �ۿ� ���ƿ並 �������ϴ�.\n";
			else
				cout << "���ƿ並 �����߽��ϴ�.\n";
			break;
		case 4: 
			my_flags ^= op_shared; 
			if (my_flags & op_shared)
				cout << "�� ���� Ÿ�Ӷ��ο� �����߽��ϴ�.\n";
			else
				cout << "������ �����߽��ϴ�.\n";
			break;
		case 5:
			my_flags |= op_deleted;
			cout << "���� �����߽��ϴ�.\n";
			break;
		case 6:
			canLoop = false;
			break;
		default:
			cout << "�߸� �� �Է��Դϴ�.\n";
			break;
		}
	}
	
	cout << "\n���� ����\n";
	for (size_t i = 0; i < 5; i++)
	{
		string funcName = list[i].first;
		unsigned int funcBit = list[i].second;
		if (my_flags & funcBit)
		{
			cout << funcName << "����\n";
		}
	}

	return 0;
}