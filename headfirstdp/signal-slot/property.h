#ifndef _PROPERTY_H
#define _PROPERTY_H

#include "signal.h"

template<class T>
class property
{
   T val_;
   signal<T> sig_;

  public:

   property(T const& val): val_(val)
   {
   }

   void set(T const &val)
     {
        val_ = val;
        sig_.emit(val_);
     }

   signal<T> const &on_change() const
     {
        return sig_;
     }

   virtual property<T> &operator=(property<T> const &rhs)
     {
        set(rhs.val_);
        return *this;
     }

   virtual property<T> &operator=(T const &rhs)
     {
        set(rhs);
        return *this;
     }
};


#endif
