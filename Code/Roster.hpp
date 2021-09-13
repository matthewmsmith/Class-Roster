#ifndef Roster_h
#define Roster_h
#include <iostream>


using namespace std;

class Roster {
public:
    Student* classRosterArray[5];
    int nextPosition = 0;
    Roster(); // DEFAULT CONSTRUCTOR
    
    
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    
    // REMOVES A STUDENT BASED ON THE ID CONDITION
    void remove(string studentID);
    
    // PRINTS ALL STUDENT OBJECT
    void printAll();
    
    // PRINTS THE AVERAGE DAYS FROM THREE COURSES THE STUDENT WAS ENROLLED IN
    void printAverageDaysInCourse(string studentID);
    
    // PRINTS ALL INVALID EMAILS FROM ALL STUDENT OBJECTS
    void printInvalidEmails();
    
    // PRINTS THE DEGREE PROGRAM FROMT THE ENUM
    void printDegreeProgram(DegreeProgram degreeProgram);
    
    // DESTRUCTOR
    ~Roster();
};
#endif
