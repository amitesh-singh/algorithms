#include <iostream>
#include <shared_mutex>
#include <thread>
#include <mutex>
//shared_mutex: refer https://en.cppreference.com/w/cpp/thread/shared_mutex

class thread_safe_counter {
     unsigned int value_{0};
     mutable std::shared_mutex m_;

    public:

     unsigned int get() const {
          //Shared mutexes are especially useful when shared data can be safely read by any number of threads simultaneously, but a thread may only write the same data when no other thread is reading or writing at the same time.
          std::shared_lock lk(m_);
          return value_;
     }
     void increment() {
          std::unique_lock lk(m_);
          ++value_;
     }

     void reset() {
          std::unique_lock lk(m_);
          value_ = 0;
     }
};
#include <vector>

std::vector<int> range(int start, int end)
{
   //throw exception if start > end or end < start
   std::vector<int> v;
   for (int i = start; i <= end; ++i) {
        v.push_back(i);
   }
   return v;
}
int main()
{
   thread_safe_counter tsc;
   std::vector<std::thread> threads;

   std::mutex m;
   for (int i : range(1, 10))
       threads.emplace_back(std::thread([&tsc, &m]()->void {
                            m.lock();
                            std::cout << "thread id: " << std::this_thread::get_id() << '\n';
                            std::cout << "increment: \n";
                            m.unlock();
                            tsc.increment();
                            std::cout << tsc.get(); std::cout << '\n';
                         }));

   for (auto &t: threads)
     t.join();
   return 0;
}
