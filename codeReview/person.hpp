#ifndef PERSON_HPP
#define PERSON_HPP

#include<string>
#include<sstream>

class person    
{
    public:
        person(const int& age, const std::string& name);
        int getAge() const;
        std::string getName() const;

        void setAge(const int& newAge);
        void setName(const std::string& newName);
        
        virtual std::string toString() const;
    private:
        int age;
        std::string name;

};


#endif