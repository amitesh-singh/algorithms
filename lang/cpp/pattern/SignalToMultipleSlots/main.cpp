#include "Signal.h"
#include<iostream>
#include <functional>

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
	using __f = std::function<void(void)>; 

	Hello hello;
	World world;
	nonstd::signal<__f> sig;
	sig.connect(std::bind(&func));
	sig.connect(std::bind(&Hello::operator (),&hello));
	sig.connect(std::bind(&World::operator (),&world));
	//connect to all slots
	sig();

	return 0;
}