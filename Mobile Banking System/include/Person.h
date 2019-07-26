#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Person
{
    private:
        string name;
        string NID_no;

    protected:

    public:
        Person();
        virtual ~Person();
        Person(const Person& other);

        string Getname() { return name; }
        void Setname(string val) { name = val; }

        string GetNID_no() { return NID_no; }
        void SetNID_no(string val) { NID_no = val; }
};

#endif // PERSON_H
