#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;
mutex mtx; // mutual exclusion : 상호배제, 서로 못 건드리게 함

int main()
{
	//// 논리적 프로세서 수
	//cout << thread::hardware_concurrency() << endl;
	//// 이 함수가 실행되고 있는 스레드 아이디
	//cout << this_thread::get_id() << endl;
	/*const int num_pro = std::thread::hardware_concurrency();
	
	cout << std::this_thread::get_id() << endl;

	vector<std::thread> my_threads;
	my_threads.resize(num_pro);

	for (auto& t : my_threads)
	{
		t = std::thread([]() {
			cout << std::this_thread::get_id() << endl;
			while (true) {}
		});
	}

	for (auto& t : my_threads)
	{
		t.join();
	}*/

	auto work_func = [](const string & name)
	{
		for (int i = 0; i < 5; ++i)
		{
			this_thread::sleep_for(std::chrono::milliseconds(100));

			mtx.lock();
			cout << name << " " << this_thread::get_id() << " is working " << i << "\n";
			mtx.unlock();
		}
	};

	auto t1 = std::thread(work_func, "Yunki");
	auto t2 = std::thread(work_func, "Taewon");

	t1.join();
	t2.join();

	return 0;
}
