#include<iostream>
using namespace std;
template<typename T,typename ret_type,typename arg1,typename arg2=int>
struct Type
{
	private:
	T *ptr;
	typedef ret_type (T::*MembFuncPtr1)(arg1);
	typedef ret_type (T::*MembFuncPtr2)(arg1,arg2);
	MembFuncPtr1 func_ptr1;
	public:
	Type(T *p,MembFuncPtr1 mem):ptr(p),func_ptr1(mem){}
	void execute(arg1 param)
	{
		(ptr->*func_ptr1)(param);
	}

};

class A
{
	public:
	void callme(int )
	{
		cerr << __PRETTY_FUNCTION__ << endl;
	}
};
int main(int argc,char **argv)
{
	A aa;
	Type<A,void,int> type(&aa,&A::callme);

	type.execute(10);

	return 0;
}
