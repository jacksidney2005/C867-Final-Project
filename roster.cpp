#include "roster.h"
#include "student.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

Roster::~Roster() {}

// E3 functions
void Roster::add(
    string studentID, 
    string firstName,
    string lastName,
    string emailAddress,
    int age, 
    int daysInCourse1,
    int daysInCourse2,
    int daysInCourse3,
    DegreeProgram degreeProgram) {

    this->ensureSize();

    int avgCourseDays[] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[numStudents] = new Student(
        studentID, firstName, lastName, emailAddress, age, avgCourseDays, degreeProgram
    );

    numStudents++;
}

void Roster::remove(string studentID) {
    bool found = false;
    int length = this->numStudents;

    for(int i = 0; i < length; i++) {
        if (found) {
            // Copy the remainder of the array into the "gap"
            classRosterArray[i-1] = classRosterArray[i];
            continue;
        }
        
        if( this->classRosterArray[i] != nullptr && 
            this->classRosterArray[i]->getStudentID() == studentID) {
            
            // Delete the item
            delete classRosterArray[i];
            found = true;
        }
    }

    if (found) {
        numStudents--;
    } else {
        cout << "Student was not found" << endl;
    }
}

void Roster::printAll() {
    for(int i = 0; i < numStudents; i++) {
        classRosterArray[i] -> Student::print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    for(int i = 0; i < numStudents; i++) {
        if(studentID == classRosterArray[i] -> Student::getStudentID()) {
            int* days = classRosterArray[i] -> getDaysToComplete();
            int avgDays = (days[0] + days[1] + days[2]) / 3;

            cout << avgDays << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    for(int i = 0; i < numStudents; i++) {
        string email = classRosterArray[i] -> Student::getEmailAddress();
        bool valid = true;
        
        if (email.find(' ') != string::npos) {
            valid = false;
        } else if (email.find('@')  == string::npos) {
            valid = false;
        } else if (email.find('.') == string::npos) {
            valid = false;
        }

        if (valid == false) { cout << email << " is invalid." << endl; }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for(int i = 0; i < numStudents; i++) {
        if (degreeProgram == classRosterArray[i] -> Student::getDegree()) {
            classRosterArray[i] -> Student::print();
        }
    }
}

void Roster::parseStudentInfo(string studentInfo) {
    vector<string> info;
    string element = "";
    DegreeProgram inputDegree;

    stringstream stream (studentInfo);
    
    while(getline(stream, element, ',')) {
        info.push_back(element);
    }

    if (info[8] == "SECURITY") {
        inputDegree = DegreeProgram::SECURITY;
    } else if(info[8] == "NETWORK") {
        inputDegree = DegreeProgram::NETWORK;
    } else if(info[8] == "SOFTWARE") {
        inputDegree = DegreeProgram::SOFTWARE;
    }

    this -> add(info[0], info[1], info[2], info[3], stoi(info[4]), stoi(info[5]), stoi(info[6]), 
        stoi(info[7]), inputDegree);
}

void Roster::ensureSize() {
    // Do we have at least one array slot available for the next add?
    // => numStudents == capacity
    // => capacity *= 2 (or =1 if capacity is zero), then copy old data to new array

    if (this->numStudents == this->capacity) {
        // Grow to twice the size
        int newCapacity = this->capacity == 0 ? 1 : this->capacity * 2;
        Student** newArray = new Student*[newCapacity];

        for (int i = 0; i < newCapacity; i++) {
            if (i < this->numStudents) {
                // Copy from old array
                newArray[i] = this->classRosterArray[i];
            } else {
                // Initialize to null
                newArray[i] = nullptr;
            }
        }

        if (this->classRosterArray != nullptr) {
            // Clean up the old array (but not the contents, because they were copied)
            delete [] this->classRosterArray;
        }

        this->capacity = newCapacity;
        this->classRosterArray = newArray;
    }
}
