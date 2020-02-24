#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

using namespace std;

class LogFile
{
 ofstream f;
 std::mutex mu;
 std::mutex mu_open;
 std::once_flag flag;

 public:

 LogFile() = default;
 ~LogFile()
   {
      f.close();
   }

 void sharedPrint(string msg, int id)
   {
        {
           //what we wanted was to open the file just once 
           /*
              std::unique_lock<std::mutex> locker(mu_open);
              if (!f.is_open())
              f.open("log.txt");
            */
           std::call_once(flag, [&] {
                          if (!f.is_open())
                            f.open("log.txt");
                            });
        }

      std::unique_lock<std::mutex> locker(mu);

      f << msg << id << endl;
   }
};

void func1(LogFile &logger)
{
   for (int i = 0; i > -100; i--)
     logger.sharedPrint("From thread1: ", i);
}

int main()
{
   LogFile logger;
   std::thread t1(func1, std::ref(logger));
   t1.join();

   for (int i = 0; i < 100; ++i)
     logger.sharedPrint("From Main: ", i);

   return 0;
}
