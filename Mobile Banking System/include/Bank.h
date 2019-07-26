#ifndef BANK_H
#define BANK_H

#include <fstream>
#include <vector>

#include "Account_User.h"

class Account_Agent;

class Bank
{
    private:
        static double total_balance;
        static double total_agent_balance;
        static double total_user_balance;
        static double total_revenue;
        static double withdraw_charge;
        static double sending_charge;

    protected:

    public:
        Bank();
        virtual ~Bank();
        Bank(const Bank& other);

        double Gettotal_balance() { return total_balance; }
        double Gettotal_agent_balance() { return total_agent_balance; }
        double Gettotal_user_balance() { return total_user_balance; }
        double Gettotal_revenue() { return total_revenue; }
        double Getwithdraw_charge() { return withdraw_charge; }
        double Getsending_charge() { return sending_charge; }

        static void Add_2_Agent_Balance(double);
        static void Add_2_User_Balance(double);
        static void Add_2_Total_Balance(double);
        static void Add_2_Revenue(double);

        static void Load_Bank_Database();
        static void Update_Bank_Database();

        friend bool Send_Money_Agent(double, long long, long long, bool, bool);
        friend bool Send_Money_User(double, long long, long long, bool);
        friend bool Cash_Out(double, long long, long long);
};

#endif // BANK_H
