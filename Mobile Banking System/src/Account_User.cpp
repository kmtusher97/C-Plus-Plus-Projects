#include "Account_User.h"

long long Account_User::number_of_user = 0;

Account_User::Account_User()
{
    Person();
    ID = -1;
    mobile_no = "00000000000";
    NID_no_SIM = "0000000000000";
    PIN = ".....";
    balance = 0.0;
}
Account_User::Account_User(const Account_User& other):Person(other) { *this = other; }
Account_User::~Account_User() { }

void Account_User::Check_Balance(string pin)
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

void Account_User::Change_PIN(string mbl, string nid, string nid1, string pin)
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
Account_User Account_User::operator += (Account_User other) const
{
    Account_User tmp;
    tmp = other;
    tmp.balance = balance+other.balance;
    return tmp;
}
