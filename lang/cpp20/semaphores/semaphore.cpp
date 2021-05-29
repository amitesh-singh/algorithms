#include <mutex>
#include <condition_variable>
#include "semaphore.h"

namespace nonstd
{
   void semaphore::acquire()
     {
        // This locks the mutex until it is destroyed at method exit.
        std::unique_lock<std::mutex> lck(m_mux);

        // Check the mutex value, and wait if need be.
        if(--m_value < 0)
          {
             // Make us wait.  When we wait, the mutex is unlocked until the
             // wait ends.
             m_waitcond.wait(lck);
          }
     }

   /* Semaphore up operation. */
   void semaphore::release()
     {
        // This locks the mutex until it is destroyed at method exit.
        std::unique_lock<std::mutex> lck(m_mux);

        // Start a waiting thread if required.
        if(++m_value <= max_value) m_waitcond.notify_one();
     }
}
