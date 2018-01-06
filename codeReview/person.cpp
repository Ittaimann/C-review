#include "person.hpp"

person::person(const int &age, const std::string &name)
    :age{age},name{name}
    {
    }


void person::setAge(const int& newAge)
{
    this->age=newAge;
}
void person::setName(const std::string& newName)
{ 
    this->name = newName;
}


std::string person::getName() const
{
    return this-> name;
}


int person::getAge() const
{
    return this->age;
}

std::string person::toString() const
{
    std::stringstream ss;
    ss<<"Hello my name is"<<this->getName()<<" and I am "<< this
    ->getAge()<<"years old";
    return ss.str();
}
