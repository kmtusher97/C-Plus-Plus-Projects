#ifndef FRIEND_FUNCTIONS_H_INCLUDED
#define FRIEND_FUNCTIONS_H_INCLUDED

Bank MobileBank;
Database DB;

int userid = 10000;
int agentid = 1111;

bool Send_Money_Agent(double amount, long long sender, long long receiver, bool type, bool cash)
{
    Message msg;
    string sndr = DB.Agent_DB[sender-agentid].mobile_no;
    if(!DB.Find_User(receiver) && !DB.Find_Agent(receiver))
    {
        msg.User_Error(sndr);
        return false;
    }
    if(DB.Agent_DB[sender-agentid].balance<amount)
    {
        msg.Error_Message_Balance(sndr);
        return false;
    }

    DB.Agent_DB[sender-agentid].balance -= amount;
    if(type==false) /// Agent to User transfer
    {
        DB.User_DB[receiver-userid].balance += amount;
        double blnc = DB.Agent_DB[sender-agentid].balance;
        double blnc1 = DB.User_DB[receiver-userid].balance;
        string rcvr = DB.User_DB[receiver-userid].mobile_no;

        msg.Send_Money_Message(amount, 0, blnc, sndr, rcvr);
        msg.Cash_In_Message(amount, 0, blnc1, sndr, rcvr);

        MobileBank.Add_2_Agent_Balance(-amount);
        MobileBank.Add_2_User_Balance(amount);
    }
    else /// Agent to Agent Transfer
    {
        DB.Agent_DB[receiver-agentid].balance += amount;
        double blnc = DB.Agent_DB[sender-agentid].balance;
        double blnc1 = DB.Agent_DB[receiver-agentid].balance;
        string rcvr = DB.Agent_DB[receiver-agentid].mobile_no;

        msg.Send_Money_Message(amount, 0, blnc, sndr, rcvr);
        msg.Cash_In_Message(amount, 0, blnc1, sndr, rcvr);
    }
    if( cash )
    {
        DB.Agent_DB[sender-agentid].cash_balance += amount;
    }
    return true;
}

bool Send_Money_User(double amount, long long sender, long long receiver, bool type)
{
    Message msg;
    string sndr = DB.User_DB[sender-userid].mobile_no;
    if(!DB.Find_User(receiver) && !DB.Find_Agent(receiver))
    {
        msg.User_Error(sndr);
        return false;
    }
    double fee = amount * MobileBank.sending_charge;
    if(DB.User_DB[sender-userid].balance<fee + amount)
    {
        msg.Error_Message_Balance(sndr);
        return false;
    }

    DB.User_DB[sender-userid].balance -= (amount+fee);
    if(type==false) /// User to User transfer
    {
        DB.User_DB[receiver-userid].balance += amount;
        double blnc = DB.User_DB[sender-userid].balance;
        double blnc1 = DB.User_DB[receiver-userid].balance;
        string rcvr = DB.User_DB[receiver-userid].mobile_no;

        msg.Send_Money_Message(amount, fee, blnc, sndr, rcvr);
        msg.Cash_In_Message(amount, 0, blnc1, sndr, rcvr);

        MobileBank.Add_2_User_Balance(-fee);
    }
    else /// User to Agent Transfer
    {
        DB.Agent_DB[receiver-agentid].balance += amount;
        double blnc = DB.User_DB[sender-userid].balance;
        double blnc1 = DB.Agent_DB[receiver-agentid].balance;
        string rcvr = DB.Agent_DB[receiver-agentid].mobile_no;

        msg.Send_Money_Message(amount, fee, blnc, sndr, rcvr);
        msg.Cash_In_Message(amount, 0, blnc1, sndr, rcvr);

        MobileBank.Add_2_Agent_Balance(amount);
        MobileBank.Add_2_User_Balance(-(amount+fee));
    }
    MobileBank.Add_2_Revenue(fee);
    return true;
}

bool Cash_Out(double amount, long long agnt, long long usr)
{
    Message msg;
    string sndr = DB.Agent_DB[agnt-agentid].mobile_no;
    string rcvr = DB.User_DB[usr-userid].mobile_no;
    if(amount>DB.Agent_DB[agnt-agentid].balance)
    {
        msg.Error_Message_Balance(sndr);
        msg.cmd_Message(rcvr);
        cout<<"Error"<<endl;
        return false;
    }
    double fee = amount * MobileBank.withdraw_charge;
    DB.Agent_DB[agnt-agentid].balance -= amount;
    DB.Agent_DB[agnt-agentid].cash_balance -= amount;
    DB.User_DB[usr-userid].balance -= (amount+fee);

    msg.Withdraw_Message(amount, sndr, rcvr);
    msg.Cash_Out_Message(amount, fee, DB.User_DB[usr-userid].balance, rcvr, sndr);

    MobileBank.Add_2_Agent_Balance(-amount);
    MobileBank.Add_2_User_Balance(-(amount+fee));
    MobileBank.Add_2_Total_Balance(-amount);
    MobileBank.Add_2_Revenue(fee);
    MobileBank.Add_2_Total_Balance(fee);
    return true;
}

#endif // FRIEND_FUNCTIONS_H_INCLUDED
