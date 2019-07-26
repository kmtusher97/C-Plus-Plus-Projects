#include "Person.h"

Person::Person()
{
    name = "..........";
    NID_no = "0000000000000";
}
Person::Person(const Person& other) { *this = other; }
Person::~Person() { }

