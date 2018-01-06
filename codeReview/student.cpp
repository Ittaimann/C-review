#include "student.hpp"
student::student(const int &age, const std::string &name, const int &id, const int &year)
    :person{age,name},Id{id},Year{year}
    {};

int student::getId() const
{
    return this->Id;
}
int student::getYear() const
{
    return this->Year;
}

void student::setID(const int &newId)
{
    this->Id=newId;
}

void student::setYear(const int &newYear)
{
    this->Year=newYear;
}

std::string student::toString() const
{
    std::stringstream ss;
    ss<<"Student Id: "<< getId()<<" name: "<< getName()<< " year: "<< getYear();
    return ss.str();
}