#include "Student.hpp"
#include "Roster.hpp"



#include <iostream>

using namespace std;

int main() {
    
    Roster classRoster;
    
    // PRINT STUDENT INFORMATION.
    cout << "C867 SCRIPTING AND PROGRAMMING APPLICATION C867" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID #001283786" << endl;
    cout << "Matthew Smith" << endl;
    
    cout << endl;
    cout << "Displaying all students:" << endl;
    classRoster.printAll();
    
    cout << endl;
    cout << "Displaying Invalid emails:" << endl;
    cout << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    
    for (int i = 0; i < 5; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i] -> getStudentID());
        
    }
    
    cout << endl;
    cout << "Showing students in degree program: SOFTWARE" << endl;
    cout << endl;
    classRoster.printDegreeProgram(SOFTWARE);
    
    cout << endl;
    
    classRoster.remove("A3");
    cout << endl;
    
    classRoster.printAll();
    
    cout << endl;
    classRoster.remove("A3");
    
    cout<< "DONE." << endl;

    return 0;
 
}
