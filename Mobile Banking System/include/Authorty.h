#ifndef AUTHORTY_H
#define AUTHORTY_H

#include <Person.h>


class Authorty : public Person
{
    protected:

    private:
        string password;
    public:
        Authorty();
        virtual ~Authorty();
        Authorty(const Authorty& other);

        string Getpassword() { return password; }
        void Setpassword(string val) { password = val; }

};

#endif // AUTHORTY_H
