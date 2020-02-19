#include "gumball.h"

int main()
{
    GumballMachine gm(10);
    gm.insertCoin();
    gm.insertCoin();

    gm.turnCrank();
    gm.returnCoin();
    cout << "----------------\n\n";

    gm.insertCoin();
    gm.returnCoin();

    gm.turnCrank();
    gm.returnCoin();

    return 0;
}