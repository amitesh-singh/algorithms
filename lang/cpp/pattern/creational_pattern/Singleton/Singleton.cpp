#include "Singleton.h"
#include <iostream>
using namespace std;

#define F cout<< __LINE__ << ":" << __PRETTY_FUNCTION__ << endl
template<typename T>
Singleton<T> *Singleton<T>::_instance  = 0;

template<typename T>
Singleton<T>::Singleton()
{
    F;
}
template<typename T>
Singleton<T> *Singleton<T>::Instance()
{
    F;
    if(_instance == 0)
        _instance = new Singleton<T>;

    return _instance;
}
