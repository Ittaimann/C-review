#ifndef SCHOOLCLASS_HPP
#define SCHOOLCLASS_HPP

#include "person.hpp"
#include "student.hpp"

class SchoolClass
{
    public:
        SchoolClass();
        SchoolClass(const SchoolClass& other);
        ~SchoolClass();

        SchoolClass& operator=(const SchoolClass& other);

      private:
        int classId;
        student * classRoom;

};

#endif