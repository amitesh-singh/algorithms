#include "atmmachine.h"

void CardInsertedState::insertCard()
{
    cout << "Card is already inserted\n";
}

void CardInsertedState::ejectCard()
{
    cout << "Ejecting Card\n";
    atm->changeState(new NoCardState(atm));
}

void CardInsertedState::insertPin(int pin)
{
    if (pin == atm->getAtmPin())
    {
        cout << "Pin is correct\n";
        atm->changeState(new RequestCashState(atm));
    }
    else
    {
        cout << "Pin entered is wrong\n";
    }
}

bool CardInsertedState::dispenseCash(int money)
{
    cout << "Enter pin\n";
    return false;
}

void NoCardState::insertCard()
{
    cout << "Card is inserted\n";
    atm->changeState(new CardInsertedState(atm));
}

void NoCardState::ejectCard()
{
    cout << "Card is not inserted yet\n";
}

void NoCardState::insertPin(int pin)
{
    cout << "Enter card first\n";
}

bool NoCardState::dispenseCash(int money)
{
    cout << "Enter card first\n";
    return false;
}

void RequestCashState::insertCard()
{
    cout << "Card is already inserted\n";
}

void RequestCashState::ejectCard()
{
    cout << "You can't eject card now\n";
}

void RequestCashState::insertPin(int pin)
{
    cout << "Cash will come out in a minute\n";
}

bool RequestCashState::dispenseCash(int money)
{
    cout << "cash " << money << " is getting withdrawn\n";
    atm->changeState(new NoCardState(atm));
    return true;
}

void NoCashState::insertCard()
{
    cout << "ATM went haywire\n";
}

void NoCashState::ejectCard()
{
    cout << "ATM went haywire\n";
}

void NoCashState::insertPin(int pin)
{
    cout << "ATM went haywire\n";
}

bool NoCashState::dispenseCash(int money)
{
    cout << "ATM went haywire\n";
    return false;
}

AtmMachine::AtmMachine(int money)
{
    cash = money;
    state = new NoCardState(this);
}

void AtmMachine::insertCard()
{
   state->insertCard();
}

void AtmMachine::ejectCard()
{
    state->ejectCard();
}

void AtmMachine::insertPinAndWithdrawCash(int pin, int amount)
{
    state->insertPin(pin);
    if (amount > cash)
    {
        changeState(new RequestCashState(this));
        return;
    }

    if (state->dispenseCash(amount))
    {
        cash = cash - amount;
    }

    if (cash <= 0)
    {
        changeState(new NoCashState(this));
    }
}

void AtmMachine::changeState(IState *s)
{
    delete state;
    state = s;
}

void AtmMachine::addCash(int money)
{
    cash += money;
    changeState(new NoCardState(this));
}
