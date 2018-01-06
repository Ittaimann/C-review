#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <sstream>
#include "person.hpp"


class student:public person 
{
public:
  student();
  student(const int &age, const std::string &name, const int &id, const int &year);
  virtual std::string toString() const;

  int getId() const;
  int getYear() const;

  void setID(const int& newId);
  void setYear(const int& newYear);

private:
  int Id;
  int Year;
};

#endif