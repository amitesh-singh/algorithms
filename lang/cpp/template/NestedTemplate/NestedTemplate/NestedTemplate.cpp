#include<iostream>
#include<typeinfo>

using namespace std;
/*

Note:
1. This is valid:
template <typename TTT, template <typename TT> class T>
2. This is NOT valid
template <typename TTT, template <typename TT> typename T>
*/


template<class T>
void myfunc()
{
	cout << __FUNCTION__ << endl;
}
template<template<class> class T>
void myfunc1()
{
	cout << __FUNCTION__ <<endl;
}
template<class T>
class A
{
public:
	void func()
	{
		cout << __FUNCTION__ <<	endl;
	}
};
//template template parameters
template<typename T,template<typename> class Cont>
class B:public Cont<T>
{
public:
	void func()
	{
		cout << __FUNCTION__ << endl;
	}
};
int main()
{
	myfunc<int>();
	myfunc1<A>();
	B<int,A > bb;
	bb.func();
	cout << typeid(bb).name() << endl ;
	int i;
	cin >> i;
	return 0;
}
