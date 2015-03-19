#include<iostream>

using namespace std;

template<class Derived>
class Base
{
public:
	void Implementation()
	{
		cout << __FUNCTION__ << endl;
	}
	void Interface()
	{
		static_cast<Derived *>(this)->Implementation();
	}
};

class Derived1:public Base<Derived1>
{
};
class Derived2:public Base<Derived2>
{
public:
	void Implementation()
	{
		cout << __FUNCTION__ << endl;
	}
};
int main()
{
	Derived1 der1;
	der1.Interface();
	
	Derived2 der2;
	der2.Interface();

	int i;
	cin >> i;
	return 0;
}