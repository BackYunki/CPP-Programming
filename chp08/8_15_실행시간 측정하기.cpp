#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>	// boost 에 있다가 최근에 추가된 시간 재는 라이브러리임
using namespace std;
using namespace std::chrono;

class Timer
{
	//using clock_t = ;
	using clock_t	= high_resolution_clock;
	using second_t	= duration<double, ratio<1>>;

	time_point<clock_t> start_time = clock_t::now();

public:
	void elapsed()
	{
		time_point<clock_t> end_time   = clock_t::now();
		
		cout << duration_cast<second_t>(end_time - start_time).count() << '\n';
	}
};

class MyTimer
{
private:
	time_point<high_resolution_clock> start_time = high_resolution_clock::now();
	
public:
	void elapsed() // 경과한 시간을 출력한다.
	{
		// duration<> 은 틱을 가지고 있는데, 이 틱의 개수를 리턴하는데 count() 함수다.
		time_point<high_resolution_clock> end_time = high_resolution_clock::now();
		// duration_cast 는 duration에서 static_cast 를 확장한 것이다. time_point 는 - 연산자가 오버로딩 되어 있는데.
		// 이 때 결과물이 common_type_t 다 이걸 duration 으로 캐스팅하는 과정이 아래의 코드다.
		cout << duration_cast<duration<double, std::ratio<1>>>(end_time - start_time).count();
	}
};

int main()
{
	random_device rnd_device;
	mt19937 mersenne_engine(rnd_device());	// 엔진의 인자는 Seed 다.

	vector<int> vec(100000);
	for (size_t i = 0; i < vec.size(); ++i)
		vec[i] = i;
	
	shuffle(begin(vec), end(vec), mersenne_engine);

	//for (auto& e : vec) cout << e << ' ';
	//cout << '\n';

	Timer timer;

	sort(begin(vec), end(vec));
	
	timer.elapsed();

	//for (auto &e : vec) cout << e << ' ';
	//cout << '\n';

	return 0;
}