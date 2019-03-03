#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>	// boost �� �ִٰ� �ֱٿ� �߰��� �ð� ��� ���̺귯����
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
	void elapsed() // ����� �ð��� ����Ѵ�.
	{
		// duration<> �� ƽ�� ������ �ִµ�, �� ƽ�� ������ �����ϴµ� count() �Լ���.
		time_point<high_resolution_clock> end_time = high_resolution_clock::now();
		// duration_cast �� duration���� static_cast �� Ȯ���� ���̴�. time_point �� - �����ڰ� �����ε� �Ǿ� �ִµ�.
		// �� �� ������� common_type_t �� �̰� duration ���� ĳ�����ϴ� ������ �Ʒ��� �ڵ��.
		cout << duration_cast<duration<double, std::ratio<1>>>(end_time - start_time).count();
	}
};

int main()
{
	random_device rnd_device;
	mt19937 mersenne_engine(rnd_device());	// ������ ���ڴ� Seed ��.

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