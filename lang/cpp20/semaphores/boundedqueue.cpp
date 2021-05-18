//based on producer-consumer problem

#include <iostream>
#include <thread>
#include <semaphore>
#include <queue>
#include <chrono>
#include <mutex>

template<class T, uint64_t BUFFER_SIZE = 32>
class bounded_queue
{
	std::queue<T> q;
	std::mutex items_queue;
	std::counting_semaphore<BUFFER_SIZE> fillCount{ 0 };
	std::counting_semaphore<BUFFER_SIZE> emptyCount{ BUFFER_SIZE };
	
public:
	void push(T&& d)
	{
		emptyCount.acquire();
		
		items_queue.lock();
		q.push(d);
		items_queue.unlock();

		fillCount.release();
	}

	T top()
	{
		return std::move(q.front());
	}

	T  pop()
	{
		fillCount.acquire();
		
		items_queue.lock();
		int r = q.front();
		q.pop();
		items_queue.unlock();
		
		emptyCount.release();

		return std::move(r);
	}
};

std::mutex stdout_mutex;

int i = 0;
void producer(bounded_queue<int, 16>& bq)
{
	while (true)
	{
		bq.push(i++);
		
		std::lock_guard<std::mutex> l(stdout_mutex);
		std::cout << "push: " << (i - 1) << std::endl;
	}
}

void consumer(bounded_queue<int, 16>& bq)
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds(2));
		int x = bq.pop();

		std::lock_guard<std::mutex> l(stdout_mutex);
		std::cout << "pop: " << x << std::endl;
		
	}
}

int main()
{
	bounded_queue<int, 16> bq;
	std::jthread t1(producer, std::ref(bq));
	std::jthread t2(consumer, std::ref(bq));

	return 0;
}