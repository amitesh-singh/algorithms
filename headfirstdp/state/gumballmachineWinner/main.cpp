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
    gm.turnCrank();

    return 0;
}
