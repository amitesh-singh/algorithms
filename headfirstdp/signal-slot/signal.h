//based on https://schneegans.github.io/tutorials/2015/09/20/signal-slot

#ifndef SIGNAL_H
#define SIGNAL_H
#include <map>
#include <functional>


template<typename... Args>
class signal
{
   mutable std::map<int, std::function<void(Args...)>> slots_;
   mutable int current_id_ = 0;
  public:
      signal() = default;
      ~signal() = default;

      int connect(std::function<void(Args...)> const &slot) const
        {
            slots_.insert(std::make_pair(++current_id_, slot));
            return current_id_;
        }

      void disconnect(int id) const
        {
           slots_.erase(id);
        }

      void disconnect_all() const
        {
           slots_.clear();
        }

      void emit(Args... arg)
        {
           for (auto const &it : slots_)
             it.second(arg...);
        }
};

#endif
