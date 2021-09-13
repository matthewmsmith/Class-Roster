#include "Student.hpp"
#include "Roster.hpp"
#include <iostream>
#include <sstream>

#include <string>

using namespace std;

const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Matthew, Smith,matthewmsmith1992@gmail.com,28, 15, 25, 39,SOFTWARE"
};

Roster::Roster() {
    
    istringstream dataStream;
    DegreeProgram degreeProgram;
    
    string studentID;
    string firstName;
    string lastName;
    string email;
    string age;
    string daysInCourse1;
    string daysInCourse2;
    string daysInCourse3;
    string degreeOfChoice;
    
    for (int i = 0; i < 5; i++) {
        
        // CLEARS THE DATA STREAM AND INPUTS THE STUDENT OBJECT AS A STRING OF VALUES
        dataStream.clear();
        dataStream.str(studentData[i]);
        
        // SEPERATES THE DATA INTO THE CORRECT VARIABLES USING THE COMMA DELIMITER
        // READS FROM AN INPUT STREAM AND APPENDS
        
        getline(dataStream, studentID, ',');
        getline(dataStream, firstName, ',');
        getline(dataStream, lastName, ',');
        getline(dataStream, email, ',');
        getline(dataStream, age, ',');
        getline(dataStream, daysInCourse1, ',');
        getline(dataStream, daysInCourse2, ',');
        getline(dataStream, daysInCourse3, ',');
        getline(dataStream, degreeOfChoice, ',');
        
        // CONFIRMS THE CORRECT STRING WAS CHOSEN FROM THE ENUM IN THE DEGREE HEADER
        if (degreeOfChoice == "SECURITY")
            degreeProgram = SECURITY;
        else if (degreeOfChoice == "NETWORK")
            degreeProgram = NETWORK;
        else degreeProgram = SOFTWARE;
        
        Roster::add(studentID, firstName, lastName, email, stoi(age), stoi(daysInCourse1), stoi(daysInCourse2),
                    stoi(daysInCourse3), degreeProgram);
    }
}

// CHECKES IF THERE IS AN INTEGER, AND REMOVES IT OR PRINTS OUT ID NOT FOUND
void Roster::remove(string studentID){
    int i = 0;
    
    while(i < 5) {
        if((classRosterArray[i] != nullptr) && (classRosterArray[i] -> getStudentID() == studentID)) {
            classRosterArray[i] = nullptr;
            delete classRosterArray[i];
            cout << "Removing " << studentID << ":" << endl;
            for(int j = i; j < nextPosition -1; j++){
                classRosterArray[j] = classRosterArray[j + 1];
                
            }
            nextPosition--;
        }
        i++;
    }
    cout << "The student with the ID: " << studentID << " was not found. " << endl;
}


// PRINTS ALL VALUES FOR EACH STUDENT OBJECT
void Roster::printAll() {
    for (int i = 0; i < nextPosition; i++) {
        classRosterArray[i]-> print();
    }
}

// ADD METHOD
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    
    int* daysInEachCourse = new int[3];
    daysInEachCourse[0] = daysInCourse1;
    daysInEachCourse[1] = daysInCourse2;
    daysInEachCourse[2] = daysInCourse3;
    
    classRosterArray[nextPosition] = new Student(studentID, firstName, lastName, email, age, daysInEachCourse, degreeProgram);
    nextPosition++;
}

// PRINTS THE AVERAGE OF THREE COURSES THE STUDENT IS IN
void Roster::printAverageDaysInCourse(string studentID){
    
    int* daysInCourse = new int[3];
    int averageDaysInCourses;
    
    // LOOPS THROUGH COURSES AND PLACES THE AVERAGE IN AVERAGEDAYSINCOURSES
    for(int i = 0; i < nextPosition; i++) {
        if(classRosterArray[i] -> getStudentID() == studentID) {
            daysInCourse = classRosterArray[i] -> getDaysInCourse();
            averageDaysInCourses = (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3;
            cout << "Student ID: " << studentID << ", " << "average days in course is: " << averageDaysInCourses << endl;
        }
        
    }
}

void Roster::printDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < nextPosition; i++)
        if (classRosterArray[i] != nullptr)
            if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
                classRosterArray[i]->print();
}
void Roster::printInvalidEmails(){
    
    string studentsEmail;
    int i=0;

    while(i < 5) {
        bool atSymbol = false;
        bool space = false;
        bool period = false;
        studentsEmail = classRosterArray[i] -> getEmail();
        for(int j = 0; j < studentsEmail.length(); j++) {
            if(studentsEmail[j] == '@')
                atSymbol = true;
            if(studentsEmail[j] == '.')
                period = true;
            if(studentsEmail[j] == ' ')
                space = true;
        }
        if ((atSymbol == false) || (space == true) || (period == false)) {
            cout  << classRosterArray[i] -> getEmail() << " - is invalid" << endl;
        }
        i++;
    }
}

// DESTRUCTOR
Roster::~Roster(){
    for(int i = 0; i < nextPosition; i++) {
        delete classRosterArray[i];
    }
    
}

