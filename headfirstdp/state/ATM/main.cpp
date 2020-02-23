#include "atmmachine.h"

int main()
{
    AtmMachine atm(1000);
    atm.insertCard();
    atm.insertPinAndWithdrawCash(1234, 100);

    cout << "ATM balance: " << atm.getBalance() << endl;

    atm.insertCard();
    atm.ejectCard();

    atm.insertPinAndWithdrawCash(1234, 100);

    return 0;
}
