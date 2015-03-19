//For more info
//http://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Non-Virtual_Interface

#include<iostream>
#include<vector>
using namespace std;
#define func cout << __PRETTY_FUNCTION__ << 	endl 
//Library Code Start
class Lock
{
	public:
	void lock()
	{
		func;
	}
	void unlock()
	{
		func;
	}
};
class Base
{
	private:
	Lock lock_;
	std::vector<int> data_;
	public:
	void read_from()
	{
		func;
		lock_.lock();
		read_from_impl();
		lock_.unlock();
	}
	void write_from()
	{
		func;
		lock_.lock();
		write_from_impl();
		lock_.unlock();
	}
	private:
	virtual void write_from_impl() = 0;
	virtual void read_from_impl() = 0;
};


void ProcessData(Base &base)
{
	base.read_from();
	base.write_from();
}
//Library code End



//User Code Start
class XmlDataHandler:public Base
{
	void write_from_impl()
	{
		func;
	}
	void read_from_impl()
	{
		func;
	}
	public:

};
int main(int argc,char **argv)
{
	XmlDataHandler handler;
	ProcessData(handler);


	return 0;
}
