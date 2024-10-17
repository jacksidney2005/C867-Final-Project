#include "roster.h"
#include "student.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "The program is using the C++ programming language" << endl;
    cout << "Student ID: 011741130" << endl;
    cout << "Name: Jack Bellingham" << endl;

    Roster classRoster;
    
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
        "A5,Jack,Bellingham,jacksidney2005@gmail.com,19,30,25,40,SOFTWARE"
    };

    const int studentDataLength = sizeof(studentData) / sizeof(studentData[0]);

    for(int i = 0; i < studentDataLength; i++) {
        classRoster.parseStudentInfo(studentData[i]);
    }

    classRoster.printAll();
    classRoster.printInvalidEmails();

    for(int i = 0; i < classRoster.getNumStudents(); i++) {
        classRoster.printAverageDaysInCourse(classRoster.getStudentId(i));
    }

    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}
