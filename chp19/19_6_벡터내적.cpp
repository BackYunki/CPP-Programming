#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>
#include <future>
#include <numeric>	//std::inner_product : ����
#include <execution>//parallel execution : ����ó��
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
	const uint32_t n_data = 100'000'00;		// 1������ ����
	const unsigned n_threads = 4;			// ����ó���� ������ ����

	// ���� �ʱ�ȭ
	vector<int> v0, v1;
	v0.reserve(n_data);
	v1.reserve(n_data);

	// ���� ������ ����: ���ʷ�����(���� ����̽�) ����(�õ带 �����ִ�.) -> �޸����� Ʈ������ ������ ž���ؼ� �� ���ƹ���
	random_device seed;
	mt19937 engine(seed()); // ���� ����̽��� () �����ڴ� ������ �Ǿ� ���ʷ������� �����͸� �Ѱ���.

	// 1~10������ �յ������ ����Ͽ� ���� ����: �յ�����Լ��� () �����ڴ� ���������� �޾Ƶ��δ�.
	uniform_int_distribution<> uniformDist(1, 10);

	for (uint32_t i = 0; i < n_data; ++i)
	{
		v0.push_back(uniformDist(engine));
		v1.push_back(uniformDist(engine));
	}

	// ���� ������ ���: �̳� ����
	cout << "std::inner_product \n";
	{
		const auto sta = chrono::steady_clock::now();
		const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull); // 0ull: uint64 0������ �ʱ�ȭ
		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << "\n\n";
	}

	// ���̽� ������� �߻��ϴ� ����ó��
	cout << "Naive\n";
	{
		const auto sta = chrono::steady_clock::now();
		uint64_t sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads; // ������ �ϳ��� ó���� ������ ��
		for (unsigned t = 0; t < n_threads; ++t) // std::ref �� ���۷������� ����ϴ� ����
		{
			threads[t] = std::thread(
				dotProductNaive, std::ref(v0), std::ref(v1), // �Լ�������, ���� ���� ���ڵ� ������
				t * n_per_thread, (t + 1) * n_per_thread,
				std::ref(sum)
			);
		}

		// �� ��Ű�� ���� ����~
		for (unsigned t = 0; t < n_threads; t++)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
		cout << dur.count() << '\n';
		cout << sum << '\n\n';
	}

	return 0;
}