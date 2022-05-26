#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
//#include <format>

using namespace std::literals;


void print_time(auto now)
{
   std::time_t ttp = std::chrono::system_clock::to_time_t(now);
   std::cout << "time: " << std::ctime(&ttp);
}
int main()
{

   using fifteenMins = std::chrono::duration<int, std::ratio<15 * 60>>;
   auto now = std::chrono::floor<fifteenMins>(std::chrono::system_clock::now());
//   std::cout << std::format("{:%Y-%m-%d %H:%M}\n", now);

   auto duration = std::chrono::system_clock::now() -  now;
//   std::cout << "duration: " << duration << std::endl;    
  std::cout << "duration: " << duration.count() << std::endl;
  std::cout << "duration: " << std::chrono::duration_cast<std::chrono::minutes>(duration).count() << std::endl;
  std::cout << "duration: " << std::chrono::duration_cast<std::chrono::seconds>(duration).count() << std::endl;
  std::cout << "duration: " << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - now).count() << std::endl;
  int timeout = 900 -  std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - now).count();
  std::cout << "timeout " << timeout << std::endl;

   std::cout << "floor: ";
   print_time(now);
   std::cout << "\n first time shot: ";
   print_time(std::chrono::system_clock::time_point(15min) - (std::chrono::system_clock::now() - now));
   std::cout << "current now: ";
   print_time(std::chrono::system_clock::now());

   while (1)
     {
        std::this_thread::sleep_for(std::chrono::minutes(15) - (std::chrono::system_clock::now() - now));
     }
   return 0;
}
