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
		
		item[i] = 1 << i;	// 아이템 비트번호

		cout << "아이템 이름 >> "; getline(cin, itemName); 
		cout << "아이템 가격 >> "; cin >> price; 

		sell_List.push_back(make_pair(itemName, price));
		cout << sell_List.back().first << ": " << sell_List.back().second << "원\n\n";
		
		getchar();
	}

	size_t select = 0;

	while (select != -1)
	{
		cout << "\n1. 구매\n2. 판매\n3. 나가기\n";
		cout << "지갑: " << myCash << "\n\n";
		cout << "선택 >> ";
		cin >> select;

		// 1. 구매
		if (select == 1)
		{
			// 상품목록 출력
			for (size_t i = 0; i < NumberOfItem; i++)
				cout << (i + 1) << ". " << sell_List[i].first << ": " << sell_List[i].second << "원\n";
			
			int buyNumber = 0;
			cout << "구매 >> ";
			cin >> buyNumber;
	
			string temp_Name = sell_List[buyNumber - 1].first;
			size_t temp_Price = sell_List[buyNumber - 1].second;

			if (myItem & item[buyNumber - 1])
			{
				cout << temp_Name << "를 이미 가지고 있습니다.\n";
			}
			else if (myCash >= temp_Price)
			{
				myCash -= temp_Price;
				myItem |= item[buyNumber - 1];
				cout << temp_Name << "을 " << temp_Price << "주고 구매하였습니다.\n";
			}
			else
			{
				cout << temp_Price - myCash << "원이 부족합니다.\n";
			}
		}

		// 2. 판매
		else if (select == 2)
		{
			cout << "\n인벤토리\n";
			for (size_t i = 0; i < NumberOfItem; i++)
			{
				string temp_Name = sell_List[i].first;
				int temp_Price = sell_List[i].second;

				if (myItem & item[i])
					cout << i << ". " << temp_Name << ": " << temp_Price << '\n';
			}

			int sellNumber = 0;
			cout << "판매 아이템 번호 >> ";
			cin >> sellNumber;

			if (sellNumber > NumberOfItem - 1 || sellNumber < 0)
			{
				cout << "잘못 된 입력입니다.\n";
				continue;
			}

			string temp_Name = sell_List[sellNumber].first;
			size_t temp_Price = sell_List[sellNumber].second;

			if (myItem & item[sellNumber])
			{
				myItem &= ~item[sellNumber];
				myCash += temp_Price/2.0;
				cout << temp_Name << "를 판매하여 " << temp_Price/2.0 << "를 얻었습니다.\n";
			}
			else
			{
				cout << temp_Name << "(을)를 갖고 있지 않습니다.\n";
			}
		}
		else if (select == 3)
		{
			break;
		}
		else
		{
			cout << "\n잘못 된 입력입니다.\n";
		}
	}

	cout << "\n인벤토리\n";
	for (size_t i = 0; i < NumberOfItem; i++)
	{
		if (myItem & item[i]) cout << i << ". " << sell_List[i].first << '\n';
	}
	cout << "장착할 아이템 >> ";
	cin >> select;
	if (select < 0 || select > NumberOfItem - 1) cout << "잘못된 입력입니다.\n";
	else if (myItem & item[select])
	{
		myItem ^= item[select];
		cout << "아이템을 장착하였습니다.\n";
	}
	else
	{
		cout << "해당 아이템이 존재하지 않습니다.\n";
	}

	return 0;
}