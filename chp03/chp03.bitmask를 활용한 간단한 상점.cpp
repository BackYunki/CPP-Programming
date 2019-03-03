#include <iostream>
#include <bitset>
#include <vector>
#include <utility>
#include <string>
const size_t NumberOfItem = 3;
size_t myCash = 3000;
size_t myItem = 0;

int main()
{
	using namespace std;

	unsigned int item[NumberOfItem];	
	vector<pair<string, size_t>> sell_List;
	for (size_t i = 0; i < NumberOfItem; i++)
	{
		string itemName;
		size_t price;
		
		item[i] = 1 << i;	// ������ ��Ʈ��ȣ

		cout << "������ �̸� >> "; getline(cin, itemName); 
		cout << "������ ���� >> "; cin >> price; 

		sell_List.push_back(make_pair(itemName, price));
		cout << sell_List.back().first << ": " << sell_List.back().second << "��\n\n";
		
		getchar();
	}

	size_t select = 0;

	while (select != -1)
	{
		cout << "\n1. ����\n2. �Ǹ�\n3. ������\n";
		cout << "����: " << myCash << "\n\n";
		cout << "���� >> ";
		cin >> select;

		// 1. ����
		if (select == 1)
		{
			// ��ǰ��� ���
			for (size_t i = 0; i < NumberOfItem; i++)
				cout << (i + 1) << ". " << sell_List[i].first << ": " << sell_List[i].second << "��\n";
			
			int buyNumber = 0;
			cout << "���� >> ";
			cin >> buyNumber;
	
			string temp_Name = sell_List[buyNumber - 1].first;
			size_t temp_Price = sell_List[buyNumber - 1].second;

			if (myItem & item[buyNumber - 1])
			{
				cout << temp_Name << "�� �̹� ������ �ֽ��ϴ�.\n";
			}
			else if (myCash >= temp_Price)
			{
				myCash -= temp_Price;
				myItem |= item[buyNumber - 1];
				cout << temp_Name << "�� " << temp_Price << "�ְ� �����Ͽ����ϴ�.\n";
			}
			else
			{
				cout << temp_Price - myCash << "���� �����մϴ�.\n";
			}
		}

		// 2. �Ǹ�
		else if (select == 2)
		{
			cout << "\n�κ��丮\n";
			for (size_t i = 0; i < NumberOfItem; i++)
			{
				string temp_Name = sell_List[i].first;
				int temp_Price = sell_List[i].second;

				if (myItem & item[i])
					cout << i << ". " << temp_Name << ": " << temp_Price << '\n';
			}

			int sellNumber = 0;
			cout << "�Ǹ� ������ ��ȣ >> ";
			cin >> sellNumber;

			if (sellNumber > NumberOfItem - 1 || sellNumber < 0)
			{
				cout << "�߸� �� �Է��Դϴ�.\n";
				continue;
			}

			string temp_Name = sell_List[sellNumber].first;
			size_t temp_Price = sell_List[sellNumber].second;

			if (myItem & item[sellNumber])
			{
				myItem &= ~item[sellNumber];
				myCash += temp_Price/2.0;
				cout << temp_Name << "�� �Ǹ��Ͽ� " << temp_Price/2.0 << "�� ������ϴ�.\n";
			}
			else
			{
				cout << temp_Name << "(��)�� ���� ���� �ʽ��ϴ�.\n";
			}
		}
		else if (select == 3)
		{
			break;
		}
		else
		{
			cout << "\n�߸� �� �Է��Դϴ�.\n";
		}
	}

	cout << "\n�κ��丮\n";
	for (size_t i = 0; i < NumberOfItem; i++)
	{
		if (myItem & item[i]) cout << i << ". " << sell_List[i].first << '\n';
	}
	cout << "������ ������ >> ";
	cin >> select;
	if (select < 0 || select > NumberOfItem - 1) cout << "�߸��� �Է��Դϴ�.\n";
	else if (myItem & item[select])
	{
		myItem ^= item[select];
		cout << "�������� �����Ͽ����ϴ�.\n";
	}
	else
	{
		cout << "�ش� �������� �������� �ʽ��ϴ�.\n";
	}

	return 0;
}