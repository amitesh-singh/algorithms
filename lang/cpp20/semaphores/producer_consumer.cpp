#include <iostream>
#include <semaphore>
#include <thread>
#include <vector>
#include <chrono>
#include <queue>
#include <mutex>

//refer to wiki: search "producer-consumer problem"
//https://en.wikipedia.org/wiki/Producer%E2%80%93consumer_problem
std::counting_semaphore<32> emptyCount(32); //32 is the size of queue buffer
std::counting_semaphore<32> fillCount(0); //0, not acquired state.
std::queue<int> q;
std::mutex datamutex;

int i = 0;
void producer(const char *workername, int timeout)
{
	while (1)
	{
		//down(emptyCount);
		emptyCount.acquire();

		datamutex.lock();
		q.push(i++);
		std::cout << workername << ": size:" << q.size() << std::endl;
		datamutex.unlock();
		
		//up(fillCount);
		fillCount.release();
		std::this_thread::sleep_for(std::chrono::seconds(timeout));
	}
}

void consumer(const char  *workername, int timeout)
{
	while (1)
	{
		fillCount.acquire();

		datamutex.lock();
		int r = q.front();
		q.pop();
		std::cout << workername << ": " << r << std::endl;
		datamutex.unlock();

		emptyCount.release();
		std::this_thread::sleep_for(std::chrono::seconds(timeout));
	}
}

int main()
{
	std::cout << "\n\n";
	std::thread t1(producer, std::ref("producer 1"), 1);
	std::thread t2(producer, std::ref("lazy producer =====> 2"), 5);
	std::thread t3(consumer, std::ref("consumer 1"), 3);
	std::thread t4(consumer, std::ref("Lazy Consumer ******* 2"), 10);

	t1.join();
	t2.join();
	t3.join();
	t4.join();


	return 0;
}
