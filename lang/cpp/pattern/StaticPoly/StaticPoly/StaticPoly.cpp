#include<iostream>
using namespace std;

//library code
template<typename Derived>
class Base
{
public:
	void Interface()
	{
		static_cast<Derived *>(this)->Implementation();
	}
};

//User code
class Derived:public Base<Derived>
{
public:
	void Implementation()
	{
		cout << "Derived : Implementation\n";
	}

};


int main()
{
	Derived *der = new Derived();
	der->Interface();

	delete der;

	int i;
	cin >> i;
	return 0;
}