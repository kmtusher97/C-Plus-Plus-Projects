#ifndef AUTHORITY_H
#define AUTHORITY_H

#include <Person.h>


class Authority : public Person
{
    private:
        string email;
        string password;

    protected:

    public:
        Authority();
        virtual ~Authority();
        Authority(const Authority& other);

        string Getemail() { return email; }
        void Setemail(string val) { email = val; }

        string Getpassword() { return password; }
        void Setpassword(string val) { password = val; }

        void Invest();
        void Withdraw();
        void Change_Withdraw_charge();

        void Authority_Operation();
};

#endif // AUTHORITY_H
