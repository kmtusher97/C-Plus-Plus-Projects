#include "Database.h"

Database::Database() { User_DB.clear(), Agent_DB.clear(), Authority_DB.clear(); }
Database::Database(const Database& other) { *this = other; }
Database::~Database() { }

void Database::Load_Users_Database()
{
    ifstream file_user("Databases/User_Database.txt");
    string line;
    while(getline(file_user, line))
    {
        stringstream ss(line);
        string name, nid, nid1, mbl, pin, tmp;
        long long id;
        double blc;
        ss>>name; ss>>tmp; name += (" "+tmp);
        ss>>nid; ss>>id; ss>>mbl;
        ss>>nid1; ss>>pin; ss>>blc;
        Account_User u;
        u.Setname(name);
        u.SetNID_no(nid);
        u.SetID(id);
        u.Setmobile_no(mbl);
        u.SetNID_no_SIM(nid1);
        u.SetPIN(pin);
        u.Setbalance(blc);

        User_DB.push_back(u);
        if(UserIDs.find(mbl)==UserIDs.end())
        {
            UserIDs[mbl] = id;
        }
    }
    file_user.close();
}
void Database::Load_Agents_Database()
{
    ifstream file_agent("Databases/Agent_Database.txt");
    string line;
    while(getline(file_agent, line))
    {
        string name, nid, nid1, mbl, pin, tmp;
        long long id;
        double blc, csh;
        stringstream ss(line);
        ss>>name; ss>>tmp; name += (" "+tmp);
        ss>>nid; ss>>id; ss>>mbl;
        ss>>nid1; ss>>pin; ss>>blc; ss>>csh;
        Account_Agent a;
        a.Setname(name);
        a.SetNID_no(nid);
        a.SetID_a(id);
        a.Setmobile_no(mbl);
        a.SetNID_no_SIM(nid1);
        a.SetPIN(pin);
        a.Setbalance(blc);
        a.Setcash_balance(csh);

        Agent_DB.push_back(a);
        if(AgentIDs.find(mbl)==AgentIDs.end())
        {
            AgentIDs[mbl] = id;
        }
    }

    file_agent.close();
}
void Database::Load_Autority_Database()
{
    ifstream file_authority("Databases/Authority_Database.txt");
    string line;
    while(getline(file_authority, line))
    {
        string name, nid, email, pass, tmp;
        stringstream ss(line);
        ss>>name; ss>>tmp; name += (" "+tmp);
        ss>>nid; ss>>email; ss>>pass;
        Authority a;
        a.Setname(name);
        a.SetNID_no(nid);
        a.Setemail(email);
        a.Setpassword(pass);

        Authority_DB.push_back(a);
    }
    file_authority.close();
}

void Database::Save_Database()
{
    ofstream file_user, file_agent, file_authority;
    file_user.open("Databases/User_Database.txt");
    file_agent.open("Databases/Agent_Database.txt");
    file_authority.open("Databases/Authority_Database.txt");

    for(Account_User u : User_DB)
    {
        file_user<<u.Getname()<<" "<<u.GetNID_no()<<" "<<u.GetID()<<" "<<u.Getmobile_no()<<" ";
        file_user<<u.GetNID_no_SIM()<<" "<<u.GetPIN()<<" "<<fixed<<setprecision(2)<<u.Getbalance()<<endl;
    }

    for(Account_Agent a : Agent_DB)
    {
        file_agent<<a.Getname()<<" "<<a.GetNID_no()<<" "<<a.GetID_a()<<" "<<a.Getmobile_no()<<" ";
        file_agent<<a.GetNID_no_SIM()<<" "<<a.GetPIN()<<" "<<fixed<<setprecision(2)<<a.Getbalance()<<" "<<a.Getcash_balance()<<endl;
    }

    for(Authority ath : Authority_DB)
    {
        file_authority<<ath.Getname()<<" "<<ath.GetNID_no()<<" "<<ath.Getemail()<<" "<<ath.Getpassword()<<endl;
    }

    file_user.close();
    file_agent.close();
    file_authority.close();
}

bool Database::Find_User(long long id) { return (id-10000<User_DB.size()); }
bool Database::Find_Agent(long long id) { return (id-1111<Agent_DB.size()); }
bool Database::Find_Authority(long long id) { return ((id-99999)<Authority_DB.size()); }

Account_User Database::GetUser(long long id)
{
    if(!Find_User(id)) return Account_User();
    return User_DB[id-10000];
}
Account_Agent Database::GetAgent(long long id)
{
    if(!Find_Agent(id)) return Account_Agent();
    return Agent_DB[id-1111];
}
Authority Database::GetAuthority(long long id)
{
    if(!Find_Authority(id)) return Authority();
    return Authority_DB[id-99999];
}

long long Database::GetUserID(string mbl)
{
    if(UserIDs.find(mbl)!=UserIDs.end())
    {
        return UserIDs[mbl];
    }
    else
    {
        return -1;
    }
}
long long Database::GetAgentID(string mbl)
{
    if(AgentIDs.find(mbl)!=AgentIDs.end())
    {
        return AgentIDs[mbl];
    }
    else
    {
        return -1;
    }
}
Authority Database::GetAuthorityID(string mail, string pss)
{
    for(Authority a : Authority_DB)
    {
        if(mail==a.Getemail() && pss==a.Getpassword())
        {
            return a;
        }
    }
    cout<<"INCORRECT Mail or Password"<<endl;
    return Authority();
}

void Database::Add_User(Account_User a)
{
    ofstream file_user;
    file_user.open("Databases/User_Database.txt", ofstream::out | ofstream::app);
    file_user<<"\n"<<a.Getname()<<" "<<a.GetNID_no()<<" "<<a.GetID()<<" "<<a.Getmobile_no();
    file_user<<" "<<a.GetNID_no_SIM()<<" "<<a.GetPIN()<<" "<<a.Getbalance();
    file_user.close();
}
void Database::Add_Agent(Account_Agent a)
{
    ofstream file_agent;
    file_agent.open("Databases/Agent_Database.txt", ofstream::out | ofstream::app);
    file_agent<<"\n"<<a.Getname()<<" "<<a.GetNID_no()<<" "<<a.GetID_a()<<" "<<a.Getmobile_no();
    file_agent<<" "<<a.GetNID_no_SIM()<<" "<<a.GetPIN()<<" "<<a.Getbalance()<<" "<<a.Getcash_balance();
    file_agent.close();
}


void Database::Update_User_PIN(long long id, string pin)
{
    User_DB[id-10000].SetPIN(pin);
}
void Database::Update_Agent_PIN(long long id, string pin)
{
    Agent_DB[id-1111].SetPIN(pin);
}

void Database::Show_Users_Database()
{
    for(int i=0; i<(int)User_DB.size(); i++)
    {
        Account_User u = User_DB[i];
        cout<<u.Getname()<<endl;
        cout<<u.Getmobile_no()<<endl;
        cout<<"---------------------------------"<<endl;
    }
}
void Database::Show_Agents_Database()
{
    for(int i=0; i<(int)Agent_DB.size(); i++)
    {
        Account_Agent a = Agent_DB[i];
        cout<<a.Getname()<<endl;
        cout<<a.Getmobile_no()<<endl;
        cout<<"---------------------------------"<<endl;
    }
}
