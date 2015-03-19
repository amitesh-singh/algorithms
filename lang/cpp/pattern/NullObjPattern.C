#include<iostream>
using namespace std;
class Abstract
{
	public:
	virtual ~Abstract() {}
	virtual void request() = 0;
};
class RealObject:public Abstract
{
	public:
	void request()
	{
		//do something
		cerr << __PRETTY_FUNCTION__ << endl;
	}
};

class NullObject:public Abstract
{
	public:
	void request() {/*do nothing */}
};
int main()
{
	Abstract *_client = new RealObject();
	_client->request();
	Abstract *_nullClient = new NullObject();
	_nullClient->request();

	delete _nullClient;
	delete _client;

	return 0;
}
