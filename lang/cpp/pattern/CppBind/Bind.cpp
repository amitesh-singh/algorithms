#include<iostream>
//Boost.Bind() look a like 
using namespace std;

template<class return_type,class Arg1,class Arg2>
class Bind
{
	return_type (*func)(Arg1,Arg2);
public:
	Bind(return_type (*_func)(Arg1,Arg2)):func(_func){}
	return_type operator()(Arg1 arg1,Arg2 arg2)
	{
		return func(arg1,arg2);
	}
};

template<class return_type,class Arg1,class Arg2>
Bind<return_type,Arg1,Arg2> bind(return_type (*func)(Arg1,Arg2))
{
	return Bind<return_type,Arg1,Arg2>(func);
}

int foo(int x,const int &y)
{
	return x+y;
}
int foo1(int *x,float *y)
{
	return *x + (int)*y;
}

int main(int argc,char **argv)
{
	int y =10;
	cout << bind<int,int,const int &>(&foo)(10,y);
	Bind<int,int,const int&> F(foo);
	cout << "\n"<< F(y,y);
	Bind<int,int *,float *> F1(foo1);
	float y1 = 10.12f;
	cout << "\n" << F1(&y,&y1);





	int i;
	cin >> i;

	return 0;
}