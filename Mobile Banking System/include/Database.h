#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include <sstream>
#include <vector>
#include <map>

#include "Authority.h"
#include "Account_User.h"
#include "Account_Agent.h"

using namespace std;

class Database
{
    private:
        vector<Account_User> User_DB;
        vector<Account_Agent> Agent_DB;
        vector<Authority> Authority_DB;
        map<string, long long> UserIDs;
        map<string, long long> AgentIDs;

    protected:

    public:
        Database();
        virtual ~Database();
        Database(const Database& other);

        void Load_Users_Database();
        void Load_Agents_Database();
        void Load_Autority_Database();

        void Save_Database();

        bool Find_User(long long);
        bool Find_Agent(long long);
        bool Find_Authority(long long);

        long long GetUserID(string);
        long long GetAgentID(string);
        Authority GetAuthorityID(string, string);

        Authority GetAuthority(long long);
        Account_Agent GetAgent(long long);
        Account_User GetUser(long long);

        void Add_User(Account_User);
        void Add_Agent(Account_Agent);

        void Update_User_PIN(long long, string);
        void Update_Agent_PIN(long long, string);
        //void Transection();

        void Show_Users_Database();
        void Show_Agents_Database();

        friend bool Send_Money_Agent(double, long long, long long, bool, bool);
        friend bool Send_Money_User(double, long long, long long, bool);
        friend bool Cash_Out(double, long long, long long);
};

#endif // DATABASE_H
