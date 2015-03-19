#include "Signal.h"
#include<iostream>
#include<boost/function.hpp>
#include<boost/bind.hpp>

void func()
{
	std::cout << __FUNCTION__ << std::endl;

}
class Hello
{
public:
	void operator()()
	{
		std::cout << "Hello ";
	}
};
class World
{
public:
	void operator()()
	{
		std::cout << "World";
	}
};
int main()
{
	typedef boost::function<void (void)> __f;
	Hello hello;
	World world;
	ami::signal<__f> sig;
	sig.connect(__f(boost::bind(&func)));
	sig.connect(__f(boost::bind(&Hello::operator (),&hello)));
	sig.connect(__f(boost::bind(&World::operator (),&world)));
	//connect to all slots
	sig();
	int i;
	std::cin >> i;
	return 0;
}