#include "Message.h"

Message::Message() { }
Message::~Message() { }
Message::Message(const Message& other) { *this = other; }

void Message::cmd_Message(string mbl)
{
    cout<<"<Send> Message to <+88"<<mbl<<"> || >>> ";
}
void Message::balance_Message(double balance)
{
    cout<<"Your Current Balance is TK "<<fixed<<setprecision(2)<<balance<<"."<<endl;
}
void Message::PIN_Error_Message()
{
    cout<<"Incorrect PIN!! Try again"<<endl;
}
void Message::Error_Message_Balance(string mbl)
{
    cmd_Message(mbl);
    cout<<"Insufficient Balance!"<<endl;
}
void Message::Cash_In_Message(double amount, double fee, double balance, string sender, string receiver)
{
    cmd_Message(receiver);
    cout<<fixed<<setprecision(2);
    cout<<"Cash In TK "<<amount<<" from "<<sender<<" successful. ";
    cout<<"Fee TK "<<fee<<" .";
    balance_Message(balance);
}
void Message::Cash_Out_Message(double amount, double fee, double balance, string receiver, string agent)
{
    cmd_Message(receiver);
    cout<<fixed<<setprecision(2);
    cout<<"Cash Out TK "<<amount<<" to "<<agent<<" successful.";
    cout<<"Fee TK "<<fee<<" .";
    balance_Message(balance);
}
void Message::Send_Money_Message(double amount, double fee, double balance, string sender, string receiver)
{
    cmd_Message(sender);
    cout<<fixed<<setprecision(2);
    cout<<"Send Money TK "<<amount<<" to "<<receiver<<" Successful. "<<"Fee TK "<<fee<<endl;
    balance_Message(balance);
}
void Message::Withdraw_Message(double amount, string sender, string receiver)
{
    cmd_Message(sender);
    cout<<fixed<<setprecision(2);
    cout<<"Cash Out TK "<<amount<<" to "<<receiver<<" successful."<<endl;
}
void Message::User_Error(string mbl)
{
    cmd_Message(mbl);
    cout<<"Invalid User!!!"<<endl;
}
void Message::Agent_Menu()
{
    cout<<"Mobile Banking"<<endl;
    cout<<"1 Check Balance"<<endl;
    cout<<"2 Send Money"<<endl;
    cout<<"3 Settings"<<endl;
    cout<<"4 Help"<<endl;
    cout<<"0 Exit"<<endl;
}
void Message::User_Menu()
{
    cout<<"Mobile Banking"<<endl;
    cout<<"1 Check Balance"<<endl;
    cout<<"2 Send Money"<<endl;
    cout<<"3 Cash Out"<<endl;
    cout<<"4 Settings"<<endl;
    cout<<"5 Help"<<endl;
    cout<<"0 Exit"<<endl;
}
