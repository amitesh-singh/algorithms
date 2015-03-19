#include<iostream>
#include<exception>
using namespace std;

typedef void (*pf)(); 
//pf func throw(); // error 
//typedef does not have exception specifications
//typedef void (*pf2) throw(); // error 

//void f1() throw(int);
//void f1() throw(float);

//declaration
int f1() throw (std::exception,int);
//definition - should be exact same as declaration
int f1() throw (std::exception,int)
try {
    throw std::exception();
}

catch(std::exception &e)

    cout << "error\n";
}


int main()
{
    f1();
    return 0;
}
