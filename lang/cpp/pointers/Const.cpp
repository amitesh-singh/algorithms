#include<iostream>
using namespace std;

class A
{
	int a;
public:
	A():a(0){}
	int get() const
	{
		A *ptr = const_cast<A *>(this);
		ptr->a = 10;
		return a;
	}
};
int main()
{
	A aa;
	cout << aa.get();

	const A aa1;
	aa1.get();  //undefined.
	system("PAUSE");


	return 0;
}