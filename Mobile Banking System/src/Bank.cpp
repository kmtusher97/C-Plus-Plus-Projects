#include "Bank.h"

Bank::Bank() { }
Bank::Bank(const Bank& other) { *this = other; }
Bank::~Bank() { }

/** Initializing Static variables **/
double Bank::total_balance = 0.0;
double Bank::total_agent_balance = 0.0;
double Bank::total_user_balance = 0.0;
double Bank::total_revenue = 0.0;
double Bank::withdraw_charge = 0.0;
double Bank::sending_charge = 0.0;

void Bank::Add_2_Agent_Balance(double amount) { total_agent_balance += amount; }
void Bank::Add_2_User_Balance(double amount) { total_user_balance += amount; }
void Bank::Add_2_Total_Balance(double amount) { total_balance += amount; }
void Bank::Add_2_Revenue(double amount) { total_revenue += amount; }

void Bank::Load_Bank_Database()
{
    ifstream file_bank;
    file_bank.open("Databases/Bank_Database.txt");
    double tmp;
    vector<double> v;
    while(file_bank>>tmp)
    {
        v.push_back(tmp);
    }
    total_balance = v[0];
    total_agent_balance = v[1];
    total_user_balance = v[2];
    total_revenue = v[3];
    withdraw_charge = v[4];
    sending_charge = v[5];
    file_bank.close();
}
void Bank::Update_Bank_Database()
{
    ofstream file_bank;
    file_bank.open("Databases/Bank_Database.txt");
    file_bank<<fixed<<setprecision(2);
    file_bank<<total_balance<<endl;
    file_bank<<total_agent_balance<<endl;
    file_bank<<total_user_balance<<endl;
    file_bank<<total_revenue<<endl;
    file_bank<<withdraw_charge<<endl;
    file_bank<<sending_charge<<endl;
}
