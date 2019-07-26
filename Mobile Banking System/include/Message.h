#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Message
{
    private:

    protected:

    public:
        Message();
        virtual ~Message();
        Message(const Message& other);

        void cmd_Message(string);
        void balance_Message(double);
        void PIN_Error_Message();
        void Error_Message_Balance(string);
        void Cash_In_Message(double, double, double, string, string);
        void Cash_Out_Message(double, double, double, string, string);
        void Send_Money_Message(double, double, double, string, string);
        void Withdraw_Message(double, string, string);
        void User_Error(string);

        void User_Menu();
        void Agent_Menu();
};

#endif // MESSAGE_H
