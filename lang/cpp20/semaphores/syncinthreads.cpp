#include <iostream>
#include <semaphore>
#include <thread>
#include <vector>
#include <chrono>

//we want to execute the threads in following order
// T1, T2 and then T3

std::binary_semaphore mainToT1(0), t1ToT2(0), t2ToT3(0);

void task1(int id)
{
	while (1)
	{
		mainToT1.acquire();
		std::cout << id << ": PONG\n";
		t1ToT2.release();
	}
}

void task2(int id)
{
	while (1)
	{
		t1ToT2.acquire();
		std::cout << id << ": PONG\n";
		t2ToT3.release();
	}
}

void task3(int id)
{
	while (1)
	{
		t2ToT3.acquire();
		std::cout << id << ": PONG\n";
	}
}

int main()
{
	std::thread t1(task1, 1);
	std::thread t2(task2, 2);
	std::thread t3(task3, 3);

	while (1)
	{
		std::this_thread::sleep_for(std::chrono::seconds(3));
		std::cout << "PING->\n";
		mainToT1.release();
	}
	t1.join();
	t2.join();
	t3.join();

	return 0;
}
