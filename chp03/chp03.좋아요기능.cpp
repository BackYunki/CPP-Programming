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
	list.push_back(make_pair("기사조회", op_viewed));
	list.push_back(make_pair("기사수정", op_edited));
	list.push_back(make_pair("좋아요", op_liked));
	list.push_back(make_pair("기사공유", op_shared));
	list.push_back(make_pair("기사삭제", op_deleted));

	unsigned char my_flags = 0;
	string article = "태원아 사랑해";
	bool canLoop = true;

	cout << "충격!). 김태원과 백윤기가 사귄지 300일!\n";
	
	while (!(my_flags & op_deleted) && canLoop)
	{
		size_t select;
		cout << "\n1. 기사보기\n2. 수정하기\n3. 좋아요\n4. 공유하기\n5. 삭제하기\n6. 나가기\n";
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
			cout << "글을 수정합니다.\n";
			getchar();
			getline(cin, article);
			my_flags &= ~op_viewed;
			break;
		case 3: 
			my_flags ^= op_liked; 
			if (my_flags & op_liked)
				cout << "이 글에 좋아요를 눌렀습니다.\n";
			else
				cout << "좋아요를 해제했습니다.\n";
			break;
		case 4: 
			my_flags ^= op_shared; 
			if (my_flags & op_shared)
				cout << "이 글을 타임라인에 공유했습니다.\n";
			else
				cout << "공유를 해제했습니다.\n";
			break;
		case 5:
			my_flags |= op_deleted;
			cout << "글을 삭제했습니다.\n";
			break;
		case 6:
			canLoop = false;
			break;
		default:
			cout << "잘못 된 입력입니다.\n";
			break;
		}
	}
	
	cout << "\n문서 정보\n";
	for (size_t i = 0; i < 5; i++)
	{
		string funcName = list[i].first;
		unsigned int funcBit = list[i].second;
		if (my_flags & funcBit)
		{
			cout << funcName << "했음\n";
		}
	}

	return 0;
}