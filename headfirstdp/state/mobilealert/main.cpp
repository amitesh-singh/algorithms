#include<iostream>

using namespace std;

class MobileAlertState
{
    public:
    virtual void alert() = 0;
};

class Call;

class Vibration: public MobileAlertState
{
    Call *call;
    public:
    Vibration(Call *c)
    {
        call = c;
    }

    void alert();
};

class Silent: public MobileAlertState
{
    Call *call;
    public:
    Silent(Call *c)
    {
        call = c;
    }

    void alert();
};

void Vibration::alert()
{
    cout << "Vibrating.." << endl;
}

void Silent::alert()
{
    cout << "Silent.." << endl;
}

class Call
{
    MobileAlertState *state;
    public:

    Call()
    {
        state = new Vibration(this);
    }

    ~Call()
    {
        delete state;
    }

    void alert()
    {
        state->alert();
    }

    void setAlertState(MobileAlertState *s)
    {
        delete state;
        state = s;
    }
};


int main()
{
    Call call;

    call.alert();
    call.alert();

    call.setAlertState(new Silent(&call));

    call.alert();
    call.alert();
    
    return 0;
}