#include "student.h"
#include <iostream>

using namespace std;

// Accessor functions
string Student::getStudentID() const { return studentID; }
string Student::getFirstName() const { return firstName; }
string Student::getLastName() const { return lastName; }
string Student::getEmailAddress() const { return emailAddress; }
int Student::getAge() const { return age; }
int (&Student::getDaysToComplete())[3] { return daysToComplete; }
DegreeProgram Student::getDegree() const { return degreeProgram; }

// Mutator functions
void Student::setStudentID(string newStudentID) { studentID = newStudentID; }
void Student::setFirstName(string newFirstName) { firstName = newFirstName; }
void Student::setLastName(string newLastName) { lastName = newLastName; }
void Student::setEmailAddress(string newEmailAddress) { emailAddress = newEmailAddress; }
void Student::setAge(int newAge) { age = newAge; }

void Student::setDaysToComplete(int (&newDaysToComplete)[3]) {
    for(int i = 0; i < 3; i++) {
        daysToComplete[i] = newDaysToComplete[i];
    }
}

void Student::setDegree(DegreeProgram newDegreeProgram) { degreeProgram = newDegreeProgram; }

// Constructor functions
Student::Student() {}

Student::Student(string studentID, string firstName, string lastName, string emailAddress,
    int age, int (&daysToComplete)[3], DegreeProgram degreeProgram) {

    setStudentID(studentID);
    setFirstName(firstName);
    setLastName(lastName);
    setEmailAddress(emailAddress);
    setAge(age);
    setDaysToComplete(daysToComplete);
    setDegree(degreeProgram);
}

// Print function, prints data for a student in the class roster array
void Student::print() {
    std::cout << studentID << "\tFirst Name: " << firstName << "\tLast Name: " << lastName;
    std::cout << "\tEmail: " << emailAddress;
    std::cout << "\tAge: " << age << "\tdaysInCourse: {";

    for (int i = 0; i < 3; i++) {
        if (i > 0) std::cout << ", ";
        std::cout << daysToComplete[i];
    }

    std::cout << "}";

    string degreeString = "";

    if (getDegree() == DegreeProgram::SECURITY) {
        degreeString = "Security";
    } else if(getDegree() == DegreeProgram::NETWORK) {
        degreeString = "Network";
    } else if(getDegree() == DegreeProgram::SOFTWARE) {
        degreeString = "Software";
    }

    std::cout << "\tDegreeProgram: " << degreeString << endl;
}

Student::~Student() {}