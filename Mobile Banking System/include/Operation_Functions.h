#ifndef OPERATION_FUNCTIONS_H_INCLUDED
#define OPERATION_FUNCTIONS_H_INCLUDED

void User_Operation(Account_User u)
{
    Message msg;
    while(true)
    {
        cout<<endl;
        msg.User_Menu();
        cout<<endl;
        int ch;
        cin>>ch;
        if(ch==1)
        {
            msg.cmd_Message(u.Getmobile_no());
            cout<<"Enter the PIN"<<endl;
            string pin;
            cin>>pin;
            u.Check_Balance(pin);

            msg.cmd_Message(u.Getmobile_no());
            cout<<"1 Main Menu 0 Exit"<<endl;
            int yn;
            cin>>yn;
            if(yn!=1) break;
        }
        else if(ch==2)
        {
            msg.cmd_Message(u.Getmobile_no());
            cout<<"1 Agent 2 User"<<endl;
            int type;
            cin>>type;
            if(type==1)
            {
                msg.cmd_Message(u.Getmobile_no());
                cout<<"Enter Agent mobile no"<<endl;
                string rcvr;
                cin>>rcvr;
                long long rcvrid = DB.GetAgentID(rcvr);
                if(rcvrid==-1)
                {
                    msg.User_Error(u.Getmobile_no());
                    break;
                }

                double amount, fee;
                msg.cmd_Message(u.Getmobile_no());
                cout<<"Enter Amount"<<endl;
                cin>>amount;
                fee = amount * MobileBank.Getsending_charge();
                if(amount + fee>u.Getbalance())
                {
                    msg.cmd_Message(u.Getmobile_no());
                    msg.Error_Message_Balance(u.Getmobile_no());
                    break;
                }

                msg.cmd_Message(u.Getmobile_no());
                cout<<"Enter PIN"<<endl;
                string pin;
                cin>>pin;
                if(pin==u.GetPIN())
                {
                    bool flg = Send_Money_User(amount, u.GetID(), rcvrid, true);
                    if(!flg)
                    {
                        msg.cmd_Message(u.Getmobile_no());
                        cout<<"Send Money Failed!!"<<endl;
                        break;
                    }
                }
                else
                {
                    msg.cmd_Message(u.Getmobile_no());
                    msg.PIN_Error_Message();
                    break;
                }
            }
            else
            {
                msg.cmd_Message(u.Getmobile_no());
                cout<<"Enter User mobile no"<<endl;
                string rcvr;
                cin>>rcvr;
                long long rcvrid = DB.GetUserID(rcvr);
                if(rcvrid==-1)
                {
                    msg.User_Error(u.Getmobile_no());
                    break;
                }

                double amount, fee;
                msg.cmd_Message(u.Getmobile_no());
                cout<<"Enter Amount"<<endl;
                cin>>amount;
                fee = amount * MobileBank.Getsending_charge();
                if(amount + fee>u.Getbalance())
                {
                    msg.cmd_Message(u.Getmobile_no());
                    msg.Error_Message_Balance(u.Getmobile_no());
                    break;
                }

                msg.cmd_Message(u.Getmobile_no());
                cout<<"Enter PIN"<<endl;
                string pin;
                cin>>pin;
                if(pin==u.GetPIN())
                {
                    bool flg = Send_Money_User(amount, u.GetID(), rcvrid, false);
                    if(!flg)
                    {
                        msg.cmd_Message(u.Getmobile_no());
                        cout<<"Send Money Failed!!"<<endl;
                        break;
                    }
                }
                else
                {
                    msg.cmd_Message(u.Getmobile_no());
                    msg.PIN_Error_Message();
                    break;
                }

            }

            msg.cmd_Message(u.Getmobile_no());
            cout<<"1 Main Menu 0 Exit"<<endl;
            int yn;
            cin>>yn;
            if(yn!=1) break;
        }
        else if(ch==3)
        {
            Message msg;
            msg.cmd_Message(u.Getmobile_no());
            cout<<"Enter Agent's Mobile no"<<endl;
            string mbl;
            cin>>mbl;
            long long id = DB.GetAgentID(mbl);
            if(id==-1)
            {
                msg.User_Error(u.Getmobile_no());
                break;
            }
            msg.cmd_Message(u.Getmobile_no());
            cout<<"Enter Amount"<<endl;
            double amount, fee;
            cin>>amount;
            msg.cmd_Message(u.Getmobile_no());
            cout<<"Enter PIN"<<endl;
            string pin;
            cin>>pin;
            if(pin!=u.GetPIN())
            {
                msg.cmd_Message(u.Getmobile_no());
                msg.PIN_Error_Message();
                break;
            }
            fee = amount * MobileBank.Getwithdraw_charge();
            if(amount + fee>u.Getbalance())
            {
                msg.Error_Message_Balance(u.Getmobile_no());
                break;
            }
            bool flg = Cash_Out(amount, id, u.GetID());
            if(!flg)
            {
                msg.cmd_Message(u.Getmobile_no());
                cout<<"Cash Out Failed"<<endl;
                break;
            }

            break;
        }
        else if(ch==4)
        {
            Message msg;
            msg.cmd_Message(u.Getmobile_no());
            cout<<"1 Change PIN 0 Exit"<<endl;
            int t;
            cin>>t;
            if(t==0) break;
            string nid, nid1, pin;
            msg.cmd_Message(u.Getmobile_no());
            cout<<"Enter your NID no"<<endl;
            cin>>nid;
            msg.cmd_Message(u.Getmobile_no());
            cout<<"Enter your NID no of the SIM Card"<<endl;
            cin>>nid1;
            msg.cmd_Message(u.Getmobile_no());
            cout<<"Enter your current PIN"<<endl;
            cin>>pin;
            u.Change_PIN(u.Getmobile_no(), nid, nid1, pin);

            DB.Update_User_PIN(u.GetID(), u.GetPIN());
            break;
        }
        else if(ch==5)
        {
            Message msg;
            msg.cmd_Message(u.Getmobile_no());
            cout<<"Please call helpline 1234"<<endl;

            msg.cmd_Message(u.Getmobile_no());
            cout<<"1 Main Menu 0 Exit"<<endl;
            int yn;
            cin>>yn;
            if(yn!=1) break;
        }
        else break;
    }
}

void Agent_Operation(Account_Agent a)
{
    Message msg;
    while(true)
    {
        cout<<endl;
        msg.Agent_Menu();
        cout<<endl;
        int ch;
        cin>>ch;
        if(ch==1)
        {
            msg.cmd_Message(a.Getmobile_no());
            cout<<"Enter the PIN"<<endl;
            string pin;
            cin>>pin;
            a.Check_Balance(pin);

            msg.cmd_Message(a.Getmobile_no());
            cout<<"1 Main Menu 0 Exit"<<endl;
            int yn;
            cin>>yn;
            if(yn!=1) break;
        }
        else if(ch==2)
        {
            msg.cmd_Message(a.Getmobile_no());
            cout<<"1 Agent 2 User"<<endl;
            int type;
            cin>>type;
            if(type==1)
            {
                msg.cmd_Message(a.Getmobile_no());
                cout<<"Enter Agent mobile no"<<endl;
                string rcvr;
                cin>>rcvr;
                long long rcvrid = DB.GetAgentID(rcvr);
                if(rcvrid==-1)
                {
                    msg.User_Error(a.Getmobile_no());
                    break;
                }

                double amount, fee;
                msg.cmd_Message(a.Getmobile_no());
                cout<<"Enter Amount"<<endl;
                cin>>amount;
                fee = 0.0;
                if(amount + fee>a.Getbalance())
                {
                    msg.cmd_Message(a.Getmobile_no());
                    msg.Error_Message_Balance(a.Getmobile_no());
                    break;
                }

                msg.cmd_Message(a.Getmobile_no());
                cout<<"Enter PIN"<<endl;
                string pin;
                cin>>pin;
                if(pin==a.GetPIN())
                {
                    bool flg = Send_Money_Agent(amount, a.GetID_a(), rcvrid, true, true);
                    if(!flg)
                    {
                        msg.cmd_Message(a.Getmobile_no());
                        cout<<"Send Money Failed!!"<<endl;
                        break;
                    }
                }
                else
                {
                    msg.cmd_Message(a.Getmobile_no());
                    msg.PIN_Error_Message();
                    break;
                }
            }
            else
            {
                msg.cmd_Message(a.Getmobile_no());
                cout<<"Enter User mobile no"<<endl;
                string rcvr;
                cin>>rcvr;
                long long rcvrid = DB.GetUserID(rcvr);
                if(rcvrid==-1)
                {
                    msg.User_Error(a.Getmobile_no());
                    break;
                }

                double amount, fee;
                msg.cmd_Message(a.Getmobile_no());
                cout<<"Enter Amount"<<endl;
                cin>>amount;
                fee = 0.0;
                if(amount + fee>a.Getbalance())
                {
                    msg.cmd_Message(a.Getmobile_no());
                    msg.Error_Message_Balance(a.Getmobile_no());
                    break;
                }

                msg.cmd_Message(a.Getmobile_no());
                cout<<"Enter PIN"<<endl;
                string pin;
                cin>>pin;
                if(pin==a.GetPIN())
                {
                    bool flg = Send_Money_Agent(amount, a.GetID_a(), rcvrid, false, true);
                    if(!flg)
                    {
                        msg.cmd_Message(a.Getmobile_no());
                        cout<<"Send Money Failed!!"<<endl;
                        break;
                    }
                }
                else
                {
                    msg.cmd_Message(a.Getmobile_no());
                    msg.PIN_Error_Message();
                    break;
                }

            }

            msg.cmd_Message(a.Getmobile_no());
            cout<<"1 Main Menu 0 Exit"<<endl;
            int yn;
            cin>>yn;
            if(yn!=1) break;
        }
        else if(ch==3)
        {
            Message msg;
            msg.cmd_Message(a.Getmobile_no());
            cout<<"1 Change PIN 0 Exit"<<endl;
            int t;
            cin>>t;
            if(t==0) break;
            string nid, nid1, pin;
            msg.cmd_Message(a.Getmobile_no());
            cout<<"Enter your NID no"<<endl;
            cin>>nid;
            msg.cmd_Message(a.Getmobile_no());
            cout<<"Enter your NID no of the SIM Card"<<endl;
            cin>>nid1;
            msg.cmd_Message(a.Getmobile_no());
            cout<<"Enter your current PIN"<<endl;
            cin>>pin;
            a.Change_PIN(a.Getmobile_no(), nid, nid1, pin);

            DB.Update_User_PIN(a.GetID_a(), a.GetPIN());
            break;
        }
        else if(ch==4)
        {
            Message msg;
            msg.cmd_Message(a.Getmobile_no());
            cout<<"Please call helpline 1234"<<endl;

            msg.cmd_Message(a.Getmobile_no());
            cout<<"1 Main Menu 0 Exit"<<endl;
            int yn;
            cin>>yn;
            if(yn!=1) break;
        }
        else break;
    }
}

#endif // OPERATION_FUNCTIONS_H_INCLUDED
