#ifndef ACCOUNT_USER_H
#define ACCOUNT_USER_H

#include "Person.h"
#include "Message.h"

class Account_User : public Person
{
    private:
        long long ID;
        string mobile_no;
        string NID_no_SIM;
        double balance;
        string PIN;
        static long long number_of_user;

    protected:

    public:
        Account_User();
        virtual ~Account_User();
        Account_User(const Account_User& other);

        long long GetID() { return ID; }
        void SetID(long long val) { ID = val; }

        string Getmobile_no() { return mobile_no; }
        void Setmobile_no(string val) { mobile_no = val; }

        string GetNID_no_SIM() { return NID_no_SIM; }
        void SetNID_no_SIM(string val) { NID_no_SIM = val; }

        double Getbalance() { return balance; }
        void Setbalance(double val) { balance = val; }

        string GetPIN() { return PIN; }
        void SetPIN(string val) { PIN = val; }

        long long Getnumber_of_user() { return number_of_user; }

        void Check_Balance(string);
        void Cash_In_User();
        //void Cash_Out();
        void Send_Money();
        void Change_PIN(string, string, string, string);

        string User_Input();
        void Send_Message(string, string);

        Account_User operator += (Account_User other) const;

        friend bool Send_Money_Agent(double, long long, long long, bool, bool);
        friend bool Send_Money_User(double, long long, long long, bool);
        friend bool Cash_Out(double, long long, long long);
};

#endif // ACCOUNT_USER_H
