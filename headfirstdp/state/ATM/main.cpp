#include "atmmachine.h"

int main()
{
    AtmMachine atm(1000);
    atm.insertCard();
    atm.insertPinAndWithdrawCash(1234, 100);

    cout << "ATM balance: " << atm.getBalance() << endl << "\n";

    atm.insertCard();
    atm.ejectCard();
    atm.insertPinAndWithdrawCash(1234, 100);
    
    cout << "ATM balance: " << atm.getBalance() << endl<< "\n";

    atm.insertCard();
    atm.insertPinAndWithdrawCash(1245, 100);
    
    cout << "ATM balance: " << atm.getBalance() << endl<< "\n";

    atm.insertCard();
    atm.insertPinAndWithdrawCash(1234, 900);

    cout << "ATM balance: " << atm.getBalance() << endl<< "\n";

    return 0;
}
