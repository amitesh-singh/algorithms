#ifndef __semaphore_h__
#define __semaphore_h__

#include <mutex>
#include <condition_variable>

namespace nonstd
{
   class semaphore
     {
        const static int BUFFER_SIZE = 1024;
       public:
           semaphore(int init): m_value(init) { }

           /* Semaphore down operation. */
           void acquire();

           /* Semaphore up operation. */
           void release();
       private:
           int m_value;                    // Value of semaphore.
           std::mutex m_mux;               // Controls access.
           std::condition_variable m_waitcond; // Controls waiting and restart
           int max_value = BUFFER_SIZE;
     };
}

#endif
