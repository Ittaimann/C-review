CXX = g++ 
CXXFLAGS = -Wall -g -std=c++11
 
Output: main.o person.o student.o
	g++ main.o person.o student.o -o a.out 

main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp

student.o: person.o student.cpp student.hpp
	g++ $(CXXFLAGS) -c student.cpp

person.o: person.cpp person.hpp
	g++ $(CXXFLAGS) -c person.cpp 

clean: 
	rm *.o a.out