#include <iostream>
#include "person.hpp"
#include "student.hpp"
int main(){

     person bill(50,"bill");
    person jane(0," ");
    student ke(1,"ke",10,10);
    

    jane.setAge(100);
    jane.setName("FL:KSJDLF");
    std::cout << ke.toString() << std::endl;
    ke.setID(001);
    ke.setYear(1);
    std::cout<<ke.toString()<<std::endl;
    std::cout<< jane.toString() <<std::endl;
    std::cout << bill.toString() << std::endl; 

    return 0;
}
































