#ifndef Student_hpp
#define Student_hpp

#include <iostream>
#include <string>
#include <stdio.h>
#include "Degree.hpp"

using namespace std;

class Student {
    
    // VARIBLES LOCAL TO STUDENT CLASS
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    
    int age;
    int* daysInCourse;
    DegreeProgram degreeProgram;
    
    /********** CONSTRUCTORS **********/
public:
    Student(string studentID, string firstName, string lastName, string email, int age, int* daysInCourse, DegreeProgram degreeProgram);
    
    
    /*********** PUBLIC SETTERS AND GETTERS ***********/
    
    // HANDLES DEGREE PROGRAM IN ANOTHER CLASS
    DegreeProgram getDegreeProgram();
    void print();
    
    // SETS AND GETS STUDENTS IDS
    void setId(string ID);
    string getStudentID();
    
    //SETS AND GETS STUDENTS FIRST AND LAST NAME
    void setFirstName(string firstName);
    void setLastName(string lastName);
    string getFirstName();
    string getLastName();
    
    
    // SETS AND GETS EMAIL
    void setEmail(string email);
    string getEmail();
    
    // SETS AND GETS AGES
    void setAge(int age);
    int getAge();
    
    // SETS AND GETS DAYS IN COURSE
    void setDaysInCourse(int* daysInCourse);
    int* getDaysInCourse();
    
};

#endif
