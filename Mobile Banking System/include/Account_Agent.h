#ifndef ACCOUNT_AGENT_H
#define ACCOUNT_AGENT_H

#include <Person.h>

#include "Bank.h"
#include "Account_User.h"
#include "Message.h"

class Account_Agent : public Person
{
    private:
        long long ID_a;
        string mobile_no;
        string NID_no_SIM;
        double balance;
        double cash_balance;
        string PIN;
        static long long number_of_agent;

    protected:

    public:
        Account_Agent();
        virtual ~Account_Agent();
        Account_Agent(const Account_Agent& other);

        long long GetID_a() { return ID_a; }
        void SetID_a(long long val) { ID_a = val; }

        string Getmobile_no() { return mobile_no; }
        void Setmobile_no(string val) { mobile_no = val; }

        string GetNID_no_SIM() { return NID_no_SIM; }
        void SetNID_no_SIM(string val) { NID_no_SIM = val; }

        double Getbalance() { return balance; }
        void Setbalance(double val) { balance = val; }

        double Getcash_balance() { return cash_balance; }
        void Setcash_balance(double val) { cash_balance = val; }

        string GetPIN() { return PIN; }
        void SetPIN(string val) { PIN = val; }

        long long Getnumber_of_agent() { return number_of_agent; }
        //void Setnumber_of_agent(static long long val) { number_of_agent = val; }

        void Check_Balance(string);
        void Cash_In();
        //void Cash_Out();
        void User_Registration();
        void Change_PIN();
        void Agent_Recharge(double);
        void Pay_Cash(double);
        void Change_PIN(string, string, string, string);

        friend bool Send_Money_Agent(double, long long, long long, bool, bool);
        friend bool Send_Money_User(double, long long, long long, bool);
        friend bool Cash_Out(double, long long, long long);
};

#endif // ACCOUNT_AGENT_H
