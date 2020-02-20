#ifndef _GUMBALL_H
#define _GUMBALL_H

#include <iostream>
#include <ctime> // for time()
#include <cstdlib> // for rand()

using namespace std;

class State 
{
    public:
    virtual void insertCoin()    = 0;
    virtual void returnCoin()    = 0;
    virtual void turnCrank()     = 0;
    virtual void dispense()      = 0;
};

class GumballMachine
{
    State *state;
    int count = 0;
    public:
    GumballMachine(int n);
    int getCount() const { return count; }

    void insertCoin();
    void returnCoin();
    //turnCrank takes care of dispense() too.
    void turnCrank();
    
    void changeState(State *s);
    
    void releaseBall()
    {
        cout << "a gumball rolls out of the slot.\n";
        if (count != 0)
            count--;
    }

    void refill(int n);
};

class NoCoinState: public State
{
    GumballMachine *gumballMachine;
    public:
    NoCoinState(GumballMachine *gm) : gumballMachine(gm)
    {
    }
    void insertCoin() override;
    void returnCoin() override;
    void turnCrank() override;
    void dispense() override;
};

GumballMachine::GumballMachine(int n)
{
    count = n;
    if (count > 0)
        state = new NoCoinState(this);
}

class HasCoinState: public State
{
    GumballMachine *gumballMachine;
    public:
    HasCoinState(GumballMachine *gm): gumballMachine(gm)
    {
    }

    void insertCoin() override;
    void returnCoin() override;
    void turnCrank() override;
    void dispense() override;
};

class SoldState: public State
{
    GumballMachine *gumballMachine;
    public:
    SoldState(GumballMachine *gm): gumballMachine(gm) {}

    void insertCoin() override;
    void returnCoin() override;
    void turnCrank() override;
    void dispense() override;
};

class SoldOutState: public State
{
    GumballMachine *gumballMachine;
    public:
    SoldOutState(GumballMachine *gm) : gumballMachine(gm) {}

    void insertCoin() override;
    void returnCoin() override;
    void turnCrank() override;
    void dispense() override;
};

void GumballMachine::insertCoin()
{
    state->insertCoin();
}

void GumballMachine::returnCoin()
{
    state->returnCoin();
}

void GumballMachine::turnCrank()
{
    state->turnCrank();
    state->dispense();
}

void GumballMachine::changeState(State *s)
{
    delete state;
    state = s;
}

void NoCoinState::insertCoin()
{
    cout << "Coin is inserted.\n";
    gumballMachine->changeState(new HasCoinState(gumballMachine));
}

void NoCoinState::returnCoin()
{
    cout << "First insert the coin\n";
}

void NoCoinState::turnCrank()
{
    cout << "First, insert the coin.\n";
}

void NoCoinState::dispense()
{
    cout << "First, insert the coin\n";
}

void HasCoinState::insertCoin()
{
    cout << "Coin is already inserted.\n";
}

void HasCoinState::returnCoin()
{
    cout << "returning the inserted coin.\n";
    gumballMachine->changeState(new NoCoinState(gumballMachine));
}

class WinnerState:public State
{
    GumballMachine *gumballMachine;
    public:
    WinnerState(GumballMachine *gm)
    {
        gumballMachine = gm;
    }

    void insertCoin()
    {
        cout << "Already inserted the coin\n";
    }

    void returnCoin()
    {
        cout << "Can't return the coin\n";
    }

    void turnCrank()
    {
        cout << "Crank is already turned\n";
    }

    void dispense()
    {
        cout << "WINNER!!!!!!!\n";
        gumballMachine->releaseBall();
        if (gumballMachine->getCount() == 0)
            gumballMachine->changeState(new SoldOutState(gumballMachine));
        else
        {
            gumballMachine->releaseBall();
            gumballMachine->changeState(new NoCoinState(gumballMachine));
        }
    }
};

void HasCoinState::turnCrank()
{
    srand(time(nullptr));
    int chances = rand() % 11;
    if (chances  == 0 && gumballMachine->getCount() > 0)
        gumballMachine->changeState(new WinnerState(gumballMachine));
    else
    {
        gumballMachine->changeState(new SoldState(gumballMachine));
    }
}

void HasCoinState::dispense()
{
    cout << "Turn the crank, first\n";
}

void SoldState::insertCoin()
{
    cout << "Can't insert coin\n";
}

void SoldState::returnCoin()
{
    cout << "Can't return coin\n";
}

void SoldState::turnCrank()
{
    cout << "Already crank is turned\n";
}

void SoldState::dispense()
{
    gumballMachine->releaseBall();
    if (gumballMachine->getCount() > 0)
        gumballMachine->changeState(new NoCoinState(gumballMachine));
    else
    {
        cout << "Opps, out of gumballs\n";
        gumballMachine->changeState(new SoldOutState(gumballMachine));
    }
}

void SoldOutState::insertCoin()
{
    cout << "Out of gumballs\n";
}

void SoldOutState::returnCoin()
{
    cout << "Out of gumballs\n";
}

void SoldOutState::turnCrank()
{
    cout << "Out of gumballs\n";
}

void SoldOutState::dispense()
{
    cout << "Out of gumball\n";
}

void GumballMachine::refill(int n)
{
    count += n;
    changeState(new NoCoinState(this));
}


#endif