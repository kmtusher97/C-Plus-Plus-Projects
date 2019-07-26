#include "Account_Agent.h"

long long Account_Agent::number_of_agent = 0;

Account_Agent::Account_Agent()
{
    Person();
    ID_a = -1;
    mobile_no = "00000000000";
    NID_no_SIM = "0000000000000";
    PIN = ".....";
    balance = 0.0;
    cash_balance = 0.0;
}
Account_Agent::~Account_Agent() { }
Account_Agent::Account_Agent(const Account_Agent& other) { *this = other; }

void Account_Agent::Check_Balance(string pin)
{
    Message msg;
    msg.cmd_Message(mobile_no);
    if(pin!=PIN)
    {
        msg.PIN_Error_Message();
        return;
    }
    msg.balance_Message(balance);
}
void Account_Agent::Agent_Recharge(double amount)
{
    balance += amount;
}
void Account_Agent::Pay_Cash(double amount)
{
    cash_balance -= amount;
}
void Account_Agent::Change_PIN(string mbl, string nid, string nid1, string pin)
{
    string _nid = GetNID_no();
    if(mbl==mobile_no && nid==_nid && nid1==NID_no_SIM && pin==PIN)
    {
        string pn;
        cout<<"Enter the new PIN"<<endl;
        cin>>pn;
        SetPIN(pn);
    }
    else
    {
        cout<<"Some Fields are wrong, Try again!!!"<<endl;
    }
}
