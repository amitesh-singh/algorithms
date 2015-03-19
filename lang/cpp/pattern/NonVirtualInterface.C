//http://altdevblogaday.org/2011/01/28/non-virtual-interfaces/
#include<iostream>
using namespace std;

class Interface
{
	virtual void InternalExecute()
	{
		cerr << __PRETTY_FUNCTION__ << endl;
	}
	public:
	virtual ~Interface(){}
	void Execute()
	{
		InternalExecute();
	}
};
class ChildInterface:public Interface
{
	private:
	void InternalExecute()
	{
		cerr << __PRETTY_FUNCTION__ << endl;
	}

};
int main()
{
	Interface *intf = new ChildInterface();
	intf->Execute();

	delete intf;

	return 0;
}
