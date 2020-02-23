#ifndef _ATM_MACHINE_H
#define _ATM_MACHINE_H

#include <iostream>

using namespace std;

class IState
{
    public:
    virtual void insertCard() = 0;
    virtual void ejectCard() = 0;
    virtual void insertPin(int pin) = 0;
    virtual void dispenseCash(int money) = 0;
};

class AtmMachine 
{
    IState *state;
    int cash = 0;
    int atmPin = 1234;
    public:
    AtmMachine(int money);

    int getAtmPin() { return atmPin;}
    void insertCard();
    void ejectCard();
    void insertPinAndWithdrawCash(int pin, int amount);
    void changeState(IState *s);
    void addCash(int money);
    int getBalance() { return cash; }
};

class CardInsertedState: public IState
{
    AtmMachine *atm;
    public:
    CardInsertedState(AtmMachine *a)
    {
        atm = a;
    }

    void insertCard() override;
    void ejectCard() override;
    void insertPin(int pin) override;
    void dispenseCash(int money) override;
};

class NoCardState: public IState
{
    AtmMachine *atm;
    public:
    NoCardState(AtmMachine *a)
    {
        atm = a;
    }
    void insertCard() override;
    void ejectCard() override;
    void insertPin(int pin) override;
    void dispenseCash(int money) override;
};

class RequestCashState: public IState
{
    AtmMachine *atm;
    public:
    RequestCashState(AtmMachine *a)
    {
        atm = a;
    }
    void insertCard() override;
    void ejectCard() override;
    void insertPin(int pin) override;
    void dispenseCash(int money) override;
};

class NoCashState: public IState
{
    AtmMachine *atm;
    public:
    NoCashState(AtmMachine *a)
    {
        atm = a;
    }
    void insertCard() override;
    void ejectCard() override;
    void insertPin(int pin) override;
    void dispenseCash(int money) override;
};

#endif