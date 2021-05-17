#include <iostream>
#include <semaphore>
#include <thread>
#include <vector>
#include <chrono>

std::binary_semaphore prepareSignal(0);

void pong()
{
	while (1)
	{
		prepareSignal.acquire();
		std::cout << "PONG" << std::endl;
	}
}

int main()
{
	std::thread t1(pong);
	
	while (1)
	{
		std::this_thread::sleep_for(std::chrono::seconds(3));
		std::cout << "PING->\n";
		prepareSignal.release();
	}
	t1.join();

	return 0;
}
