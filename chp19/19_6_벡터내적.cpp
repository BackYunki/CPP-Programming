#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>
#include <future>
#include <numeric>	//std::inner_product : 내적
#include <execution>//parallel execution : 병렬처리
using namespace std;

mutex mtx;

void dotProductNaive(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, uint64_t& sum)
{
	for (unsigned i = i_start; i < i_end; ++i)
	{
		sum += v0[i] * v1[i];
	}
}

int main()
{
	// Constants
	const uint32_t n_data = 100'000'00;		// 1억차원 벡터
	const unsigned n_threads = 4;			// 병렬처리할 쓰레드 갯수

	// 벡터 초기화
	vector<int> v0, v1;
	v0.reserve(n_data);
	v1.reserve(n_data);

	// 랜덤 데이터 생성: 제너레이터(랜덤 디바이스) 생성(시드를 갖고있다.) -> 메르세네 트위스터 엔진에 탑재해서 더 꼬아버림
	random_device seed;
	mt19937 engine(seed()); // 랜덤 디바이스의 () 연산자는 재정의 되어 제너레이터의 포인터를 넘겨줌.

	// 1~10까지의 균등분포를 사용하여 값을 대입: 균등분포함수의 () 연산자는 랜덤엔진을 받아들인다.
	uniform_int_distribution<> uniformDist(1, 10);

	for (uint32_t i = 0; i < n_data; ++i)
	{
		v0.push_back(uniformDist(engine));
		v1.push_back(uniformDist(engine));
	}

	// 단일 스레드 방식: 겁나 느림
	cout << "std::inner_product \n";
	{
		const auto sta = chrono::steady_clock::now();
		const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull); // 0ull: uint64 0값으로 초기화
		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << "\n\n";
	}

	// 레이스 컨디션이 발생하는 병렬처리
	cout << "Naive\n";
	{
		const auto sta = chrono::steady_clock::now();
		uint64_t sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads; // 쓰레드 하나당 처리할 데이터 수
		for (unsigned t = 0; t < n_threads; ++t) // std::ref 는 레퍼런스임을 명시하는 것임
		{
			threads[t] = std::thread(
				dotProductNaive, std::ref(v0), std::ref(v1), // 함수포인터, 펑터 전달 인자들 열거함
				t * n_per_thread, (t + 1) * n_per_thread,
				std::ref(sum)
			);
		}

		// 일 시키기 위해 조인~
		for (unsigned t = 0; t < n_threads; t++)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
		cout << dur.count() << '\n';
		cout << sum << '\n\n';
	}

	return 0;
}