#include <iostream>
#include <ctime>	// std::time();
#include <cstdlib>	// std::rand(), std::srand();
#include <random>	// c++11 에 추가된 라이브러리

int main()
{
	using namespace std;
	//// 랜덤넘버를 가지고 만든 프로그램의 디버깅은 시드를 고정시킨뒤 할것
	//srand(static_cast<unsigned int>(time(0)));

	//for (size_t i = 1; i <= 100; i++)
	//{
	//	cout << rand() << '\t';
	//	if (i % 5 == 0) cout << endl;
	//}

	random_device rd;	
	mt19937 mersenne(rd());	// create a mesenne twister,
	uniform_int_distribution<> dice(1, 100);

	int chk[101] = { 0, };

	for (size_t i = 1; i <= 1000; ++i)
	{
		unsigned int num = dice(mersenne);
		//cout << num << endl;
		chk[num]++;
	}

	for (size_t i = 1; i <= 100; i++)
	{
		cout << i << ": " << chk[i]/1000.0 << endl;
	}

	return 0;
}