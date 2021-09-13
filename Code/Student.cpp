
#include "Student.hpp"
#include <string>
using namespace std;


// DEFAULT CONSTRUCTOR

// CONSTRUCTOR
Student::Student(string studentID, string firstName, string lastName, string email, int age, int* daysInCourse, DegreeProgram degreeProgram) {
    this ->  studentID = studentID;
    this ->  firstName = firstName;
    this ->  lastName = lastName;
    this ->  email = email;
    this ->  age = age;
    this ->  daysInCourse = daysInCourse;
    this -> degreeProgram = degreeProgram;
};

// SETTER AND GETTER IDS
void Student::setId(string studentID) {
    this -> studentID = studentID;
}
string Student::getStudentID()  {
    return studentID;
}
// SETTER AND GETTER FIRST AND LAST NAME
void Student::setFirstName(string firstName) {
    this -> firstName = firstName;
}
void Student::setLastName(string lastName) {
    this -> lastName = lastName;
}
string Student::getFirstName() {
    return firstName;
}
string Student::getLastName() {
    return lastName;
}

// SETTER AND GETTER EMAIL
void Student::setEmail(string email) {
    this -> email = email;
}
string Student::getEmail() {
    return email;
}

//SETTER AND GETTER AGE
void Student::setAge(int age) {
    this -> age = age;
}
int Student::getAge() {
    return age;
}
enum DegreeProgram Student::getDegreeProgram() {
    return degreeProgram;
}
void Student::print(){
    cout << studentID << "\t" << firstName << "\t" << lastName  << "\t" << age << "\t {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "} \t"  <<
    " \t"; switch(degreeProgram) {
        case SECURITY :
            cout << "SECURITY";
            break;
        case NETWORK:
            cout << "NETWORK";
            break;
        case SOFTWARE:
            cout << "SOFTWARE";
            break;
        default:
            cout << "Unknown Degree" << endl;
    }
    cout << endl;
    return;
}
// SETTER AND GETTER DAYS IN COURSE
void Student::setDaysInCourse(int* daysInCourse) {
    int i = 0;
    while(i < 3) {
        this -> daysInCourse[i] = daysInCourse[i];
        i++;
    }
}

int* Student::getDaysInCourse() {
    return this -> daysInCourse;
}

