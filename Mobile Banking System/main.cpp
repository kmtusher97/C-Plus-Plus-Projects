#include <iostream>

#include "Bank.h"
#include "Person.h"
#include "Account_User.h"
#include "Account_Agent.h"
#include "Authority.h"
#include "Database.h"
#include "Message.h"
#include "Friend_functions.h"
#include "Operation_Functions.h"

using namespace std;

extern Bank MobileBank;
extern Database DB;

int Instructions()
{
    cout<<"Mobile User press 1"<<endl<<"Authority press 2"<<endl<<"Exit press 0"<<endl;
    int choice;
    cin>>choice;
    return choice;
}

int main()
{
    MobileBank.Load_Bank_Database();
    DB.Load_Users_Database();
    DB.Load_Agents_Database();
    DB.Load_Autority_Database();

    int choice;
    while( choice = Instructions() )
    {
        if(choice==1)
        {
            string dial, mbl;
            cout<<"User  : Dial 123 and your mobile no"<<endl;
            cout<<"Agent : Dial 321 and your mobile no"<<endl;
            cin>>dial>>mbl;
            if(dial=="123")
            {
                Message msg;
                long long id = DB.GetUserID(mbl);
                if(id==-1)
                {
                    msg.User_Error(mbl);
                    cout<<"You don't have an account"<<endl;
                }
                else
                {
                    Account_User u = DB.GetUser(id);
                    User_Operation(u);
                }
            }
            else if(dial=="321")
            {
                Message msg;
                long long id = DB.GetAgentID(mbl);
                if(id==-1)
                {
                    msg.User_Error(mbl);
                    cout<<"You don't have an account"<<endl;
                }
                else
                {
                    Account_Agent a = DB.GetAgent(id);
                    Agent_Operation(a);
                }
            }
        }
        else if(choice==2)
        {
            cout<<"Authority Login"<<endl;
            string email, pass;
            cout<<"Email    : ";
            cin>>email;
            cout<<"Password : ";
            cin>>pass;
            Authority a = DB.GetAuthorityID(email, pass);
            if(a.Getemail()=="-") continue;
            a.Authority_Operation();
        }
        else break;
    }

    DB.Save_Database();
    MobileBank.Update_Bank_Database();
    return 0;
}

