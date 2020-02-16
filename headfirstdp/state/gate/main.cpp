#include <iostream>
#include <typeinfo>

using namespace std;

class GateState
{
    public:
    string name;
    virtual void enter() = 0;
    virtual void pay() = 0;
    virtual void payOk() = 0;
    virtual void payFailed() = 0;
};

class Gate;

class OpenGateState: public GateState
{
    Gate *gate;
    
    public:
    
    OpenGateState(Gate *g): gate(g) { name = "Open";}
    
    void enter();
    void pay();
    void payOk();
    void payFailed();
};

class ClosedGateState: public GateState
{
    Gate *gate;
    public:
    ClosedGateState(Gate *g): gate(g)
    {
        name = "Closed";
    }

    void enter();
    void pay();
    void payOk();
    void payFailed();
};

class Gate 
{
    GateState *state;
    
    public:
    Gate()
    {
        state = new ClosedGateState(this);
    }

    ~Gate()
    {
        delete state;
    }

    void enter()
    {
        state->enter();
    }

    void pay()
    {
        state->pay();
    }

    void payOk()
    {
        state->payOk();
    }

    void payFailed()
    {
        state->payFailed();
    }

    void changeState(GateState *s)
    {
        delete state;
        state = s;
    }

    string getState()
    {
        return state->name;
    }

};

void OpenGateState::enter()
{
    cout << "User enters.\n";
    gate->changeState(new ClosedGateState(gate));
}

void OpenGateState::pay()
{
    cout << "payment processing\n";
    gate->changeState(new OpenGateState(gate));
}

void OpenGateState::payOk()
{
    cout << "pay ok\n";
    gate->changeState(new OpenGateState(gate));
}

void OpenGateState::payFailed()
{
    cout << "pay failed.\n";
    gate->changeState(new OpenGateState(gate));
}

void ClosedGateState::enter()
{
    cout << "user denied\n";
    gate->changeState(new ClosedGateState(gate));
}

void ClosedGateState::pay()
{
    cout << "User Pays\n";

}

void ClosedGateState::payOk()
{
    cout << "Payment Okay\n";
    gate->changeState(new OpenGateState(gate));
}

void ClosedGateState::payFailed()
{
    cout << "Payment Failed\n";
    gate->changeState(new ClosedGateState(gate));
}

int main()
{
    Gate g;
    cout << "state: " << g.getState() << endl;

    //tries to enter 
    g.enter(); //should be failed
    cout << "state: " << g.getState() << endl;
    g.pay();
    cout << "state: " << g.getState() << endl;
    g.payOk();
    cout << "state: " << g.getState() << endl;
    g.enter();
    cout << "state: " << g.getState() << endl;
    return 0;
}